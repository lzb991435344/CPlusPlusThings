//设计一通用数组类，它能够直接存取数组元素，并能够对数组进行从大到小的排序。

#include<iostream>
#include<cstring>
using namespace std;

const int Size = 5;

/**
 一、模板
	1、模板概念 模板是对具有相同特性的函数或类的再抽象，模板是一种参数多态性的工具，
 可以为逻辑功能相同而类型不同的程序提供一种代码共享的机制。 一个模板并非一个实实在在的函数或类，
 仅仅是一个函数或类的描述，是参数化的函数和类。
	2、模板分类 函数模板 类模板
	3、函数模板与模板函数 函数模板提供了一种通用的函数行为，
 该函数行为可以用多种不同的数据类型进行调用，编译器会据调用类型自动将它实例化为具体数据类型的函数代码，
 也就是说函数模板代表了一个函数家族。 与普通函数相比，函数模板中某些函数元素的数据类型是未确定的，
 这些元素的类型将在使用时被参数化；与重载函数相比，函数模板不需要程序员重复编写函数代码，它可以自动生
 成许多功能相同但参数和返回值类型不同的函数。

  二、函数模板
  1、函数模板的定义
  template是定义模板的关键字；写在一对<>中的T1，T2，…是模板参数，其中的class表示其后的参数可以是
  任意类型。 模板参数常称为类型参数或类属参数，在模板实例化（即调用模板函数时）时需要传递的实参是
  一种数据类型，如int或double之类。 函数模板的参数表中常常出现模板参数，如T1，T2 

  2、使用函数模板的注意事项

   ① 在定义模板时，不允许template语句与函数模板定义之间有任何其他语句。
	template <class T>
	int x;                 //错误，不允许在此位置有任何语句
	T min(T a,T b){…}


	② 函数模板可以有多个类型参数，但每个类型参数都必须用关键字class或typename限定。
	此外，模板参数中还可以出现确定类型参数，称为非类型参数。
	template <class T1,class T2,class T3,int T4>
	T1 fx(T1 a, T 2 b, T3 c){…}
	在传递实参时，非类型参数T4只能使用常量


	③ 不要把这里的class与类的声明关键字class混淆在一起，虽然它们由相同的字母组成，
	但含义是不同的。这里的class表示T是一个类型参数，可以是任何数据类型，如int、float、
	char等，或者用户定义的struct、enum或class等自定义数据类型。


	④ 为了区别类与模板参数中的类型关键字class，标准C++提出?了用typename作为模板参数的类型关键字，
	同时也支持使用class。比如，把min定义的template 写成下面的形式是完全等价的：

	template <typename T>
	T min(T a,T b){…}

	3.函数模板的实例化

	3.1 实例化时间
	(1)实例化发生的时机 模板实例化发生在调用模板函数时。当编译器遇到程序中对函数模板的调用时，
	它才会根据调用语句中实参的具体类型，确定模板参数的数据类型，并用此类型替换函数模板中的模
	板参数，生成能够处理该类型的函数代码，即模板函数。

	(2)当多次发生类型相同的参数调用时，只在第1次进行实例化。假设有下面的函数调用：
	int x=min(2,3);
	int y=min(3,9);
	int z=min(8.5);
	编译器只在第1次调用时生成模板函数，当之后遇到相同类型的参数调用时，不再生成其他模板函数，
	它将调用第1次实例化生成的模板函数。

	3.2 实例化方式
	(1)隐式实例化
	编译器能够判断模板参数类型时，自动实例化函数模板为模板函数
	template <typename T> T max (T, T);
	…
	int i = max (1, 2);
	float f = max (1.0, 2.0);
	char ch = max (‘a’, ‘A’);
	…


	(2)显示实例化explicit instantiation 时机,编译器不能判断模板参数类型或常量值 
	需要使用特定数据类型实例化 

	语法形式:: 模板名称<数据类型,…,常量值,…> (参数)
	template <class T> T max (T, T);
	…
	int i = max (1, ‘2’);
	// error: data type can’t be deduced
	int i = max<int> (1, ‘2’);
	…

	4.函数模板的特化
	(1)特化的原因 但在某些情况下，模板描述的通用算法不适合特定的场合（数据类型等） 比如：如max函数

	char * cp = max (“abcd”, “1234”);
	实例化为：char * max (char * a, char * b){return a > b ? a : b;}
	这肯定是有问题的，因为字符串的比较为：

	char * max (char * a, char * b)
	{	return strcmp(a, b)>0 ? a : b;   }

	(2)特化
		所谓特化，就是针对模板不能处理的特殊数据类型，编写与模板同名的特
	殊函数专门处理这些数据类型。
	模板特化的定义形式： template <> 返回类型 函数名<特化的数据类型>(参数表) { …… } 
	说明： 
	① template < >是模板特化的关键字，< >中不需要任何内容；
	② 函数名后的< >中是需要特化处理的数据类型。


	5.说明 
	① 当程序中同时存在模板和它的特化时，特化将被优先调用；
	② 在同一个程序中，除了函数模板和它的特化外，还可以有同名的普通函数。
	其区别在于C++会对普通函数的调用实参进行隐式的类型转换，但不会对模板函数及特化函数的
	参数进行任何形式的类型转换。

	6.调用顺序 当同一程序中具有模板与普通函数时，
	其匹配顺序如下： 完全匹配的非模板函数 完全匹配的模板函数 类型相容的非模板函数 

	三、类模板 
	1.类模板的概念 
		类模板可用来设计结构和成员函数完全相同，但所处理的数据类型不同的通用类。

	2.类模板的声明

	template<class T1,class T2,…>
	class 类名{
    	……								// 类成员的声明与定义
		}
	其中T1、T2是类型参数 类模板中可以有多个模板参数，包括类型参数和非类型参数

	3.非类型参数

	 非类型参数是指某种具体的数据类型，在调用模板时只能为其提供用相应类型的常数值。
	非类型参数是受限制的，通常可以是整型、枚举型、对象或函数的引用，以及对象、函数或类
	成员的指针，但不允许用浮点型（或双精度型）、类对象或void作为非类型参数。

	在下面的模板参数表中，T1、T2是类型参数，T3是非类型参数。
	template<class T1, class T2, int T3>
	在实例化时，必须为T1、T2提供一种数据类型，为T3指定一个整常数（如10），该模板才能被正确地实例化。


	4.类模板的成员函数的定义 
	方法1：在类模板外定义，语法 template <模板参数列表> 返回值类型 类模板名<模板参数名表>::成员函数名
	(参数列表){……}; 方法2：成员函数定义，与常规成员函数的定义类似，另外 “模板参数列表”引入的
	“类型标识符”作为数据类型使用 “模板参数列表”引入的“普通数据类型常量”作为常量使用 
	
	5.类模板特化

	特化 
	解决例9-9的方法是特化。即用与该模板相同的名字为某种数据类型专门重写一个模板类。 

	类模板有两种特化方式：
	(1)一种是特化整个类模板，
	(2)另一种是特化个别成员函数 特化成员函数的方法：

	template <> 返回类型 类模板名<特化的数据类型>::特化成员函数名(参数表){
		 …… 								//函数定义体
	}
	template<>  void Array<char *>::Sort(){
		for(int i=0;i<Size-1;i++){
		int p=i;
		for(int j=i+1;j<Size;j++)
			if(strcmp(a[p],a[j])<0)
				p=j;
		char* t=a[p];
		a[p]=a[i];
		a[i]=t;
	 }
	}
*/


template<class T>
class Array {
private:
	T a[Size];
public:
	Array() {
		for (int i = 0; i < Size; i++) {
			a[i] = 0;
		}
	}
	T &operator[](int i);
	void Sort();
};

template<class T> T& Array<T>::operator[](int i) {
	if (i<0 || i > Size - 1) {
		cout << "\n数组下标越界！" << endl;
		exit(1);
	}
	return a[i];
}

template<class T> void Array<T>::Sort() {
	int p;
	for (int i = 0; i < Size - 1; i++) {
		p = i;
		for (int j = i; j < Size; j++) {
			if (a[p] < a[j])
				p = j;
		}
		T t = a[p];
		a[p] = a[i];
		a[i] = t;
	}
}
//template <> 返回类型 类模板名<特化的数据类型>::特化成员函数名(参数表){}
template<> void Array<char *>::Sort() {
	int p;
	for (int i = 0; i < Size - 1; i++) {
		p = i;
		for (int j = i + 1; j < Size; j++)
			if (strcmp(a[p], a[j]) < 0)
				p = j;
		char* t = a[p];
		a[p] = a[i];
		a[i] = t;
	}
}

/**
int main() {
	Array<int> a1;
	Array<char*>b1;
	a1[0] = 1; a1[1] = 23; a1[2] = 6;
	a1[3] = 3; a1[4] = 9;
	a1.Sort();
	for (int i = 0; i < 5; i++)
		cout << a1[i] << "\t";
	cout << endl;
	b1[0] =(char*) "x1";	b1[1] = (char*) "ya";	b1[2] = (char*)"ad";
	b1[3] = (char*)"be";	b1[4] = (char*) "bc";
	b1.Sort();
	for (int i = 0; i < 5; i++)
		cout << b1[i] << "\t";
	cout << endl;
	system("pause");
}
*/

/**
23      9       6       3       1
ya      x1      be      bc      ad

*/