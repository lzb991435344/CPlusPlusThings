/**
1.简易版哈希表
我们将哈希表封装在一个类中,完成遍历的定义与声明以及构造、析构的实现：

template<typename Key, typename Value>
class HashTable {
private:
	const static int upperTol = 3;
	const static int lowerTol = 1;
	const static int initCapacity = 1;
	map<Key, Value> **hashtable;
	int M;
	int size;
public:
	
	 // 传参构造
	 // @param M
	 
HashTable(int M) : M(M), size(0) {
	// 这里的括号是为了初始化为0,这就可以不用写下面的代码,当然在后面add之类的操作,就不需要动态分配内存.
	// this->hashtable = new map<Key, Value> *[M]();
	this->hashtable = new map<Key, Value> *[M];
	for (int i = 0; i < M; i++) {
		this->hashtable[i] = new map<Key, Value>;
	}
}

//默认构造
 
HashTable() {
	HashTable(initCapacity);
}


  //析构函数,释放内存
 
~HashTable() {
	free(M);
}
private:
	
	 // 释放内存
	 // @param M
	 
	void free(int M) {
		for (int i = 0; i < M; i++) {
			if (hashtable[i])
				delete hashtable[i];
		}
		delete[] hashtable;

	};


	int hashFunc(Key key) {
	std::hash<Key> h;
	return (h(key) & 0x7fffffff) % M;
}
这里使用std的hash得到值之后，将其&上0x7fffffff，去掉高位的负号，转为正数，然后余上M。



(1)增操作
底层采用的是红黑树,插入是使用insert方法，通过构造一个pair来完成。 而当key存在的时候，
更新值即可，对于更新这一块，如果直接使用insert是不起作用的，比如下面测试：

 map<string,int> m{{"a",1},{"b",2}};
for(auto i:m) cout<<i.first<<" "<<i.second<<" ";
cout<<endl;
m.insert({{"a",2}});
for(auto i:m) cout<<i.first<<" "<<i.second<<" ";
cout<<endl;
m["a"]=2;
for(auto i:m) cout<<i.first<<" "<<i.second<<" ";
cout<<endl;
输出：

a 1 b 2
a 1 b 2
a 2 b 2



如果要修改key对应的value，可以通过[]来修改，还可以先删除，再插入

//添加新元素
void add(Key key, Value value) {
	// 拉链法出来的map如果为空,就动态分配一个map,然后进行插入
	// 如果key不存在就看内存是否存在,不存在,就分配,存在就插入
	if (hashtable[hashFunc(key)] == NULL || hashtable[hashFunc(key)]->count(key) == 0) {
		if (hashtable[hashFunc(key)] == NULL)
			hashtable[hashFunc(key)] = new map<Key, Value>;
		hashtable[hashFunc(key)]->insert(make_pair(key, value));
		size++;
		if (size >= maxCapacity())
			resize(2 * M);
	} else {
		// 否则,修改value.
		hashtable[hashFunc(key)]->erase(key);
		hashtable[hashFunc(key)]->insert(make_pair(key, value));
	}
}



(2)删操作
如果key存在，就删除，size--，否则返回失败标记。


 //移除Key
// @param key
// @return 0 success -1 fail

Value remove(Key key) {
	Value ret = -1;
	// 是否包含key,若包含key,则直接删除
	if (contains(key)) {
		hashtable[hashFunc(key)]->erase(key);
		size--;
		//if (size == 0) delete hashtable[hashFunc(key)];       // 可以添加这行来动态减少内存
		ret = 0;
		// initCapacity 保证不会越界
		if (size < minCapacity() && M / 2 >= initCapacity) resize(M / 2);
	}
	return ret;
}


(3)改操作
void set(Key key, Value value) {
	// key不存在
	if (!contains(key))
		hrow "key not exists!";
	// 修改value
	hashtable[hashFunc(key)]->erase(key);
	hashtable[hashFunc(key)]->insert(make_pair(key, value));
}


(4)查操作
获取key对应的value。


// 获取key对应的value
 //@param key
 //@return

Value get(Key key) {
	if (contains(key))
		return hashtable[hashFunc(key)]->at(key);
	return 0;
}
最后，上面有contains与resize等函数未提。


(5)key存在与否？

bool contains(Key key) {
	return hashtable[hashFunc(key)] == NULL || this->hashtable[hashFunc(key)]->count(key) == 0 ? false : true;
}


(6)获取size
// 获取哈希表元素个数
 //@return

int getSize() {
	return size;
}

(7)最大容量与最小容量
    //最大容量
	// @return
	
	Value maxCapacity() {
	return M * upperTol;
}


// 最小容量
//	 @return
	
Value minCapacity() {
	return M * lowerTol;
}

(8)resize函数

完成动态调整内存，将原来内存中的内容拷贝到新分配的空间，释放原空间！


// 动态调整内存,保证时间复杂度O(1)查找
//把扩容后的操作,平摊到前面每次操作,时间复杂度O(2),那就是O(1)了
// @param newM

void resize(int newM) {
	cout << "resize " << newM << endl;
	map<Key, Value> **newHashTable = new map<Key, Value> *[newM];
	for (int i = 0; i < newM; i++) {
		newHashTable[i] = new map<Key, Value>;
	}
	int oldM = M;
	this->M = newM;

	for (int i = 0; i < oldM; i++) {
		map<Key, Value> m = *(hashtable[i]);
		for (auto p : m)
			newHashTable[hashFunc(p.first)]->insert(make_pair(p.first, p.second));
	}

	free(oldM);
	this->hashtable = newHashTable;
}


(9)重载<< 操作符
声明：

private:
	template<typename K, typename V>
	// 重载<<操作符
	friend ostream &operator<<(ostream &out, HashTable<K, V> &hashTable);
定义：

template<typename K, typename V>
ostream &operator<<(ostream &out, HashTable<K, V> &hashTable) {
	hashTable.print();
	return out;
}

#include "hash.h"
#include <vector>
int main() {

	vector<string> words{"java", "c++", "c", "c++", "c#", "python", "ruby", "python",
						 "c", "c", "c++", "java", "c++", "rust", "python"};
	HashTable<string, int> ht(1);
	for (string word : words) {
		if (ht.contains(word)) {
			ht.set(word, ht.get(word) + 1);
		} else {
			ht.add(word, 1);
		}
	}
	cout<<ht;
	cout<<"size="<<ht.getSize()<<",maxCapacity="<<ht.maxCapacity()<<",minCapacity="<<ht.minCapacity()<<endl;
	string w="c++";
	ht.remove(w);
	if (ht.contains(w))
		cout << "" << w << ": " << ht.get(w) << endl;
	else
		cout << "No word " << w << " in words" << endl;
	cout<<ht;
	ht.remove("c#");
	ht.remove("java");
	ht.remove("c");
	cout<<"size="<<ht.getSize()<<",maxCapacity="<<ht.maxCapacity()<<",minCapacity="<<ht.minCapacity()<<endl;
	cout<<ht;

	return 0;
}
输出结果：

resize 2
resize 4
{c#:1,java:2,ruby:1,c:3,rust:1,python:3,c++:4}
size=7,maxCapacity=12,minCapacity=4
No word c++ in words
{c#:1,java:2,ruby:1,c:3,rust:1,python:3}
resize 2
size=3,maxCapacity=6,minCapacity=2
{python:3,ruby:1,rust:1}


2.优化哈希表
类内部开头添加下面数组：

// 素数数组
const vector<int> capacity = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317,
								196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843,
								50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};

		

去掉带参数的构造函数，修改默认构造为：

 //默认构造
 //@param M

HashTable() {
	M = capacity[capacityIndex], size = 0;
	// 这里的括号是为了初始化为0,这就可以不用写下面的代码,当然在后面add之类的操作,就不需要动态分配内存.
	// this->hashtable = new map<Key, Value> *[M]();
	this->hashtable = new map<Key, Value> *[M];
	for (int i = 0; i < M; i++) {
		this->hashtable[i] = new map<Key, Value>;
	}
}


修改add函数： 在size++后添加下面代码：

if (size >= maxCapacity() && capacityIndex + 1 < capacity.size()) {
	capacityIndex++;
	resize(capacity[M]);
}
每次resize从capacity中取值。

remove函数修改

在size--后修改：

if (size < minCapacity() && capacityIndex - 1 >= 0) {
	capacityIndex--;
	resize(capacityIndex);
}
至此，哈希表完成！测试代码同上。




*/
