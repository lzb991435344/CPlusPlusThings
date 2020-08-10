#include<iostream>
using namespace std;

/**
* @brief 构造函数不能是虚函数，而析构函数可以是虚析构函数。
 * 例如：当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。
 如果析构函数不是虚拟的，则只能调用基类析构函数。
*/
/**
为什么构造函数不能是虚函数？
(1)构造对象时，必须知道对象的类型，虚函数在运行时才能确定对象的类型
编译器无法知道构造对象的实际类型
(2)虚函数运行依赖于虚函数指针（在构造对象时进行初始化，指向正确的虚函数表）


*/


class Base {
public:
	Base() { cout << "Constructor: Base" << endl; }
	virtual ~Base() { cout << "Destructor : Base" << endl; }
};

class Derived : public Base {
public:
	Derived() { cout << "Constructor: Derived" << endl; }
	~Derived() { cout << "Destructor : Derived" << endl; }
};
/**
int main() {
	Base *Var = new Derived();
	delete Var;//析构子类对象的同时，也会虚构基类对象，调用正确的虚函数
	return 0;
}*/
/**
Constructor: Base
Constructor: Derived
Destructor : Derived
Destructor : Base

*/
