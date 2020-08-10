#include <iostream>
using namespace std;

/*
多继承下的二义性：在多继承方式下，派生类继承了多个基类的成员，当两个不同基类拥有同名成员时，
容易产生名字冲突问题。

虚拟继承引入的原因：重复基类，派生类间接继承同一基类使得间接基类（Person）在派生类中有多份拷贝，
引发二义性。

1、虚拟继承virtual inheritance的定义 语法 class derived_class : virtual […] base_class 虚基类
virtual base class 被虚拟继承的基类 在其所有的派生类中，仅出现一次

2、虚拟继承的构造次序 虚基类的初始化与一般的多重继承的初始化在语法上是一样的，但构造函数的调用顺序不同；
若基类由虚基类派生而来，则派生类必须提供对间接基类的构造（即在构造函数初始列表中构造虚基类，无论此虚基
类是直接还是间接基类） 调用顺序的规定： 先调用虚基类的构造函数，再调用非虚基类的构造函数 若同一层次中
包含多个虚基类,这些虚基类的构造函数按它们的说明的次序调用 若虚基类由非基类派生而来,则仍然先调用基类构
造函数,再调用派生类构造函数 

3、虚基类由最终派生类初始化 在没有虚拟继承的情况下，每个派生类的构造函数
只负责其直接基类的初始化。但在虚拟继承方式下，虚基类则由最终派生类的构造函数负责初始化。 在虚拟继承方
式下，若最终派生类的构造函数没有明确调用虚基类的构造函数，编译器就会尝试调用虚基类不需要参数的构造函
数（包括缺省、无参和缺省参数的构造函数），如果没找到就会产生编译错误。

*/
class A {
	int a;
public:
	A() { cout << "Constructing A" << endl; }
};
class B {
public:
	B() { cout << "Constructing B" << endl; }
};
class B1 :virtual public B, virtual public A {
public:
	B1(int i) { cout << "Constructing B1" << endl; }
};
class B2 :public A, virtual public B {
public:
	B2(int j) { cout << "Constructing B2" << endl; }
};
class D : public B1, public B2 {
public:
	D(int m, int n) : B1(m), B2(n) { cout << "Constructing D" << endl; }
	A a;
};
/**
int main() {
	D d(1, 2);
	return 0;
}*/
/**
Constructing B
Constructing A
Constructing B1
Constructing A
Constructing B2
Constructing A
Constructing D
*/