#include<iostream>
using namespace std;

//@brief 抽象类中：在成员函数内可以调用纯虚函数，在构造函数 / 析构函数内部不能使用纯虚函数
//如果一个类从抽象类派生而来，它必须实现了基类中的所有纯虚函数，才能成为非抽象类

class A {
public:
	virtual void f() = 0;  // 纯虚函数
	void g() { 
		this->f(); //函数内可以调用纯虚函数
	}
	A() {
	
	}
};

//继承A，实现A中所有的纯虚函数才能是非抽象类
class B :public A {
public:
	void f() { cout << "B:f()" << endl; }
};

/**
int main() {
	B b;
	b.g();

	getchar();
	system("pause");
	return 0;
}*/
//B:f()