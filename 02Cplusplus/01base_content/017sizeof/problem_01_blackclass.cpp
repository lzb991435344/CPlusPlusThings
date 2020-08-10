#include<iostream>

using namespace std;

/**
空类的大小为1字节
一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间。
对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
普通继承，派生类继承了所有基类的函数与成员，要按照字节对齐来计算大小
虚函数继承，不管是单继承还是多继承，都是继承了基类的vptr。(32位操作系统4字节，64位操作系统 8字节)！
虚继承,继承基类的vptr。

*/

class A {};
/**
int main()
{
	//空类大小为1
	cout << sizeof(A) << endl;//1
	return 0;
}*/