/**
 * @file first_example.cpp
 * @brief 虚函数中默认参数
 * 规则：虚函数是动态绑定的，默认参数是静态绑定的。默认参数的使用需要
 看指针或者应用本身的类型，而不是对象的类型！
 */

#include <iostream> 
using namespace std;

class Base
{
public:
	//默认参数的使用需要
	//看指针或者应用本身的类型，而不是对象的类型！
	virtual void fun(int x = 10)
	{
		cout << "Base::fun(), x = " << x << endl;
	}
};

class Derived : public Base
{
public:
	virtual void fun(int x = 20)
	{
		cout << "Derived::fun(), x = " << x << endl;
	}
};

/**
int main()
{
	Derived d1;
	Base *bp = &d1;
	
	bp->fun();  // 10
	Base* bs = new Derived();
	bs->fun();
	return 0;
}*/
/**
Derived::fun(), x = 10
Derived::fun(), x = 10
*/
