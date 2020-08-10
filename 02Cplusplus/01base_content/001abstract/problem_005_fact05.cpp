#include<iostream> 
using namespace std;

// An abstract class with constructor 
class Base
{
protected:
	int x;
public:
	virtual void fun() = 0;

	//抽象类可以有构造函数
	Base(int i) {
		cout<< "Base call()"<<endl;
		x = i; }
};

class Derived : public Base
{
	int y;
public:
	Derived(int i, int j) :Base(i) {
		cout << "Derived call()" << endl;
		y = j; }
	void fun() { cout << "x = " << x << ", y = " << y; }
};
/**
int main(void)
{
	Derived d(4, 5);
	d.fun();
	return 0;
}*/
/**
Base call()
Derived call()
x = 4, y = 5

*/