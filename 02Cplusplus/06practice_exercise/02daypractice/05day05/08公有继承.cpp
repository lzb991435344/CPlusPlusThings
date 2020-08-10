

/**
一、公有继承 1.基类中protected的成员 类内部：可以访问 类的使用者：不能访问 类的派生类成员：可以访问 
2.派生类不可访问基类的private成员 3.派生类可访问基类的protected成员 4.派生类可访问基类的public成员

二、私有继承 派生类不可访问基类的任何成员与函数

三、保护继承 派生方式为protected的继承称为保护继承，在这种继承方式下， 基类的public成员在派生类
中会变成protected成员， 基类的protected和private成员在派生类中保持原来的访问权限 注意点：当采用
保护继承的时候，由于public成员变为protected成员，因此类的使用者不可访问！而派生类可访问！

四、派生类对基类成员的访问形式 1.通过派生类对象直接访问基类成员 2.在派生类成员函数中直接访问基
类成员 3.通过基类名字限定访问被重载的基类成员名

*/
#include<iostream>
#include <string>
using namespace std;

class base {
	int x;
public:
	void setx(int n) { x = n; }
	int getx() { return x; }
	void showx() { cout << x << endl; }
};
//派生类
class derived :public base {
	int y;
public:
	void sety(int n) { y = n; }
	void sety() { y = getx(); }
	void showy()
	{
		cout << y << endl;
	}
};
//派生类不可直接访问基类的private成员，可通过基类的共有成员函数访问
/**
int main()
{
	derived obj;
	obj.setx(10);
	obj.sety(20);
	obj.showx();
	obj.showy();
	obj.sety();
	obj.showx();
	obj.showy();
	system("pause");
}*/
/**
10
20
10
10

*/

