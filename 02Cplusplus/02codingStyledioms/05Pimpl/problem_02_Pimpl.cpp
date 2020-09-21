#include <iostream>
using namespace std;

// pImpl: Pointer-to-Implementation

class private_foo; //前置声明

class foo {
public:
	foo();

	~foo();

	void bar();

private:
	private_foo *pImpl; //嵌入其他类的指针
};

class private_foo {
public:
	void bar() {
		cout << "private_foo invoke bar funciton." << endl;
	}

private:
	int m1;
	string m2;
};

foo::foo() : pImpl(new private_foo()) {
}

foo::~foo() {
}

void foo::bar() {
	pImpl->bar();
}

//调用的方法是其他类内部的成员函数
//g++ problem_02_Pimpl.cpp -o pimpl 编译
int main() {
	foo f;
	f.bar(); //private_foo invoke bar funciton.
}