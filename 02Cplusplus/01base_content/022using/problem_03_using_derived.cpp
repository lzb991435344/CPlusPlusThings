#include <iostream>
using namespace std;
/*
在派生类中使用using声明语句指定一个名字而不指定形参列表，所以一条基类成员函数的using声明
语句就可以把该函数的所有重载实例添加到派生类的作用域中。此时，
派生类只需要定义其特有的函数就行了，而无需为继承而来的其他函数重新定义。

*/
class Base {
public:
	void f() {
		cout << "f()" << endl;
	}
	void f(int n) {
		cout << "Base::f(int)" << endl;
	}
};

class Derived : private Base {
public:
	using Base::f;//将所有的重载版本添加到派生类中
	void f(int n) {
		cout << "Derived::f(int)" << endl;
	}
};
/**
int main()
{
	Base b;
	Derived d;
	d.f();
	d.f(1);
	return 0;
}*/
/*
f()
Derived::f(int)
*/