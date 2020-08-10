#include<iostream> 
using namespace std;

class Base
{
	int x;
public:
	virtual void fun() = 0;
	int getX() { return x; }
};

class Derived : public Base
{
	int y;
public:
	void fun() { cout << "fun() called"; }  // 实现了fun()函数
};
/**
int main(void)
{
	Derived d;
	d.fun();
	getchar();
	system("pause");
	return 0;
}
//fun() called
*/