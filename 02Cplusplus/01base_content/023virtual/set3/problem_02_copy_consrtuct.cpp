#include <iostream> 
using namespace std;

/**
构造函数不可以声明为虚函数。同时除了inline|explicit之外，构造函数不允许使用其它任何关键字。

为什么构造函数不可以为虚函数？
尽管虚函数表vtable是在编译阶段就已经建立的，但指向虚函数表的指针vptr是在运行阶段实例化对象时才产生的。 
如果类含有虚函数，编译器会在构造函数中添加代码来创建vptr。 问题来了，如果构造函数是虚的，
那么它需要vptr来访问vtable，可这个时候vptr还没产生。 因此，构造函数不可以为虚函数。

我们之所以使用虚函数，是因为需要在信息不全的情况下进行多态运行。而构造函数是用来初始化实例的，
实例的类型必须是明确的。 因此，构造函数没有必要被声明为虚函数。
*/

class Base
{
public:

};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived created" << endl;
	}

	Derived(const Derived &rhs)
	{
		cout << "Derived created by deep copy" << endl;
	}

	~Derived()
	{
		cout << "Derived destroyed" << endl;
	}
};

/**
int main()
{
	Derived s1;

	Derived s2 = s1; // Compiler invokes "copy constructor" 
	// Type of s1 and s2 are concrete to compiler 

	// How can we create Derived1 or Derived2 object 
	// from pointer (reference) to Base class pointing Derived object? 

	return 0;
}*/

/**
Derived created
Derived created by deep copy
Derived destroyed
Derived destroyed
*/