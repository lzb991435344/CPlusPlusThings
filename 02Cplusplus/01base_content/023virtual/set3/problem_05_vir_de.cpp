/**
 * @file vir_de.cpp
 * @brief 派生类的析构函数没有被调用!
 */

/**
析构函数可以声明为虚函数。如果我们需要删除一个指向派生类的基类指针时，
应该把析构函数声明为虚函数。 事实上，只要一个类有可能会被其它类所继承， 
就应该声明虚析构函数(哪怕该析构函数不执行任何操作)。

*/

 // CPP program without virtual destructor  
 // causing undefined behavior 
#include<iostream> 

using namespace std;

class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};
/**
int main(void)
{
	derived *d = new derived();
	base *b = d;
	delete b;
	return 0;
}*/
/**
Constructing base
Constructing derived
Destructing base

*/