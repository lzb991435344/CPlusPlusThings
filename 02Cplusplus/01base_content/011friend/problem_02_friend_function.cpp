#include <iostream>

using namespace std;

class A
{
public:
	A(int _a) :a(_a) {};
	friend int geta(A &ca);  //< 友元函数
private:
	int a;
};

//类外实现，不属于某个类
int geta(A &ca)
{
	return ca.a;
}
/**
int main()
{
	A a(3);
	cout << geta(a) << endl;//3

	return 0;
}*/