#include <iostream>

using namespace std;
/***

友元提供了一种 普通函数或者类成员函数 访问另一个类中的私有或保护成员 的机制。
也就是说有两种形式的友元：

（1）友元函数：普通函数对一个访问某个类中的私有或保护成员。

（2）友元类：类A中的成员函数访问类B中的私有或保护成员

优点：提高了程序的运行效率。

缺点：破坏了类的封装性和数据的透明性。

总结：

能访问私有成员
破坏封装性
友元关系不可传递
友元关系的单向性
友元声明的形式及数量不受限制



*/
class A
{
public:
	A(int _a) :a(_a) {

	};
	//友元类的声明在该类的声明中，而实现在该类外。
	//B是A的友元类，B可以访问A的私有成员
	friend class B;
private:
	int a;
};

class B
{
public:
	int getb(A ca) {
		return  ca.a;
	};
};

/**
int main()
{
	A a(3);
	B b;
	cout << b.getb(a) << endl;//3
	return 0;
}*/