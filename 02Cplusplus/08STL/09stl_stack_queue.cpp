/**1.stack
在stack的源码中我们关注两点：

(i)默认_Sequence为deque
(ii)内部函数实现是调用_Sequence对应容器的函数

template<typename _Tp, typename _Sequence = deque<_Tp> >
class stack
{

public:
	typedef typename _Sequence::value_type                value_type;
	typedef typename _Sequence::reference                 reference;
	typedef typename _Sequence::const_reference           const_reference;
	typedef typename _Sequence::size_type                 size_type;
	typedef          _Sequence                            container_type;

protected:
	//  See queue::c for notes on this name.
	_Sequence c;

public:
	 reference
	  top()
	  {
		__glibcxx_requires_nonempty();
		return c.back();
	  }
	void
	  push(const value_type& __x)
	  { c.push_back(__x); }
}

(1)测试stack底层容器

对于stack来说，底层容器可以是vector、deque、list，但不可以是map、set。 
由于编译器不会做全面性检查，当调用函数不存在的时候，就编译不通过，所以对于像set虽
然不能作为底层容器，但如果具有某些函数，调用仍然是成功的，直到调用的函数不存在。

int test_stack() {
	cout<<"============test_stack============="<<endl;
	clock_t timeStart = clock();
	stack<int, list<int>> c;
	for (long i = 0; i < 100000; i++)
		c.push(i+1);
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;
	cout << "use stack milli-seconds : " << (clock() - timeStart) << endl;
	timeStart=clock();
	stack<int, deque<int>> c1;
	for (long i = 0; i < 100000; i++)
		c1.push(i+1);
	cout << "stack.size()= " << c1.size() << endl;
	cout << "stack.top()= " << c1.top() << endl;
	c1.pop();
	cout << "stack.size()= " << c1.size() << endl;
	cout << "stack.top()= " << c1.top() << endl;
	cout << "use stack milli-seconds : " << (clock() - timeStart) << endl;

	// vector可以作为stack的底层容器
	stack<int, vector<int>> c2;
	for (long i = 0; i < 100000; i++)
		c2.push(i+1);
	cout << "stack.size()= " << c2.size() << endl;
	cout << "stack.top()= " << c2.top() << endl;
	c2.pop();
	cout << "stack.size()= " << c2.size() << endl;
	cout << "stack.top()= " << c2.top() << endl;
	cout << "use stack milli-seconds : " << (clock() - timeStart) << endl;
}



2.queue
在queue的源码中我们关注两点：

(1)默认_Sequence为deque
(2)内部函数实现是调用_Sequence对应容器的函数。

template<typename _Tp, typename _Sequence = deque<_Tp> >
class queue
{
public:
	typedef typename _Sequence::value_type                value_type;
	typedef typename _Sequence::reference                 reference;
	typedef typename _Sequence::const_reference           const_reference;
	typedef typename _Sequence::size_type                 size_type;
	typedef          _Sequence                            container_type;

protected:

	_Sequence c;

public:

	void push(const value_type& __x)
	{ c.push_back(__x); }

	void pop()
	{
		__glibcxx_requires_nonempty();
	  c.pop_front();
	}
}



同理，优先队列则是使用vector作为默认容器。

template<typename _Tp, typename _Sequence = vector<_Tp>,
typename _Compare  = less<typename _Sequence::value_type> >
class priority_queue
{
public:
	typedef typename _Sequence::value_type                value_type;
	typedef typename _Sequence::reference                 reference;
	typedef typename _Sequence::const_reference           const_reference;
	typedef typename _Sequence::size_type                 size_type;
	typedef          _Sequence                            container_type;

protected:
	//  See queue::c for notes on these names.
	_Sequence  c;
	_Compare   comp;

public:
	reference
	top()
	{
		__glibcxx_requires_nonempty();
		return c.front();
	}

	void
	push(const value_type& __x)
	{
		c.push_back(__x);
		std::push_heap(c.begin(), c.end(), comp);
	}

}



测试这两个容器配接器支持的底层容器：

queue

对于queue底层容器可以是deque，也可以是list，但不能是vector,map,set，使用默认的deque效率
在插入方面比其他容器作为底层要快！

int test_queue() {
	cout<<"============test_queue============="<<endl;
	clock_t timeStart = clock();
	queue<int, list<int>> c;
	for (long i = 0; i < 100000; i++) {
		c.push(i+1);
	}
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.front()= " << c.front() << endl;
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.front()= " << c.front() << endl;
	cout << "use list milli-seconds : " << (clock() - timeStart) << endl;

	timeStart=clock();
	queue<int, deque<int>> c1;
	for (long i = 0; i < 100000; i++) {
		c1.push(i+1);
	}
	cout << "stack.size()= " << c1.size() << endl;
	cout << "stack.front()= " << c1.front() << endl;
	c1.pop();
	cout << "stack.size()= " << c1.size() << endl;
	cout << "stack.front()= " << c1.front() << endl;

	cout << "use deque milli-seconds : " << (clock() - timeStart) << endl;
}
priority_queue

对于优先队列来说，测试结果发现，采用deque要比默认的vector插入速度快！ 底层支持vector、deque容器，
但不支持list、map、set。

int test_priority_queue() {
	cout<<"============test_priority_queue============="<<endl;
	clock_t timeStart = clock();

	priority_queue<int, deque<int>> c1;
	for (long i = 0; i < 100000; i++) {
		c1.push(i+1);
	}
	cout << "stack.size()= " << c1.size() << endl;
	cout << "stack.top()= " << c1.top() << endl;
	c1.pop();
	cout << "stack.size()= " << c1.size() << endl;
	cout << "stack.top()= " << c1.top() << endl;

	cout << "use deque milli-seconds : " << (clock() - timeStart) << endl;


	priority_queue<int, vector<int>> c2;
	for (long i = 0; i < 100000; i++)
		c2.push(i+1);
	cout << "stack.size()= " << c2.size() << endl;
	cout << "stack.top()= " << c2.top() << endl;
	c2.pop();
	cout << "stack.size()= " << c2.size() << endl;
	cout << "stack.top()= " << c2.top() << endl;
	cout << "use stack milli-seconds : " << (clock() - timeStart) << endl;
}
因此，stack、queue、priority_queue不被称为容器， 把它称为容器配接器。


*/



#include <iostream>
#include <queue>
#include <vector>

/**
int main() {

	std::queue<int, std::deque<int> > que;
	que.push(1);


	//大根堆，默认是less
	std::priority_queue<int, std::vector<int>, std::less<int> > pLessQueue;


	//小顶堆
	std::priority_queue<int, std::vector<int>, std::greater<int> > pGreaterQueue;

	//(1)基础类型的比较
	//(2)pair的比较，先比较第一个元素，第一个相等比较第二个。
	
	return 0;
}*/