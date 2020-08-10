// 基类指针或引用指向派生类对象时, 虚函数与非虚函数区别：
//声明Employee的print为虚函数，则可访问到Manager的print函数，非虚函数，则只能访问到Employee的print
#include<iostream>
#include<string>
using namespace std;

/**
一、多态性 多态性：多态就是在同一个类或继承体系结构的基类与派生类中，用同名函数来实现各种不同的功能。

静态绑定又称静态联编，是指在编译程序时就根据调用函数提供的信息，把它所对应的具体函数确定下来，即在编译
时就把调用函数名与具体函数绑定在一起。

动态绑定又称动态联编，是指在编译程序时还不能确定函数调用所对应的具体函数，只有在程序运行过程中才能够
确定函数调用所对应的具体函数，即在程序运行时才把调用函数名与具体函数绑定在一起。

编译时多态性： ---静态联编(连接)----系统在编译时就决定如何实现某一动作,即对某一消息如何处理.静态联编
具有执行速度快的优点.在C++中的编译时多态性是通过函数重载和运算符重载实现的。 运行时多态性： ---动态联编(连接)----系统在运行时动态实现某一动作,即对某一消息在运行过程实现其如何响应.动态联编为系统提供了灵活和高度问题抽象的优点,在C++中的运行时多态性是通过继承和虚函数实现的。

二、虚函数

虚函数的意义

1、基类与派生类的赋值相容

派生类对象可以赋值给基类对象。 派生类对象的地址可以赋值给指向基类对象的指针。 派生类对象可以作
为基类对象的引用。 赋值相容的问题： 不论哪种赋值方式，都只能通过基类对象（或基类对象的指针或引用）
访问到派生类对象从基类中继承到的成员， 不能借此访问派生类定义的成员。

2、虚函数使得可以通过基类对象的指针或引用访问派生类定义的成员。

3.Virtual关键字其实质是告知编译系统，被指定为virtual的函数采用动态联编的形式编译。

4.虚函数的虚特征：基类指针指向派生类的对象时，通过该指针访问其虚函数将调用派生类的版本。

一旦将某个成员函数声明为虚函数后，它在继承体系中就永远为虚函数了
如果基类定义了虚函数，当通过基类指针或引用调用派生类对象时，将访问到它们实际所指对象中的虚函数版本。
只有通过基类对象的指针和引用访问派生类对象的虚函数时，才能体现虚函数的特性。
派生类中的虚函数要保持其虚特征，必须与基类虚函数的函数原型完全相同，否则就是普通的重载函数，与基类的
虚函数无关。
派生类通过从基类继承的成员函数调用虚函数时，将访问到派生类中的版本。
只有类的非静态成员函数才能被定义为虚函数，类的构造函数和静态成员函数不能定义为虚函数。原因是虚函数在
继承层次结构中才能够发生作用，而构造函数、静态成员是不能够被继承的。
内联函数也不能是虚函数。因为内联函数采用的是静态联编的方式，而虚函数是在程序运行时才与具体函数动态
绑定的，采用的是动态联编的方式，即使虚函数在类体内被定义，C++编译器也将它视为非内联函数。

5.基类析构函数几乎总是为虚析构函数。 why? 假定使用delete和一个指向派生类的基类指针来销毁派生类对象，
如果基类析构函数不为虚,就如一个普通成员函数，delete函数调用的就是基类析构函数。在通过基类对象的引用或
指针调用派生类对象时，将致使对象析构不彻底！


三、纯虚函数和抽象类

1.纯虚函数概念？

仅定义函数原型而不定义其实现的虚函数 Why pure function? 实用角度：占位手段place-holder 
方法学：接口定义手段，抽象表达手段 How? class X { virtual ret_type func_name (param) = 0; } 

2.抽象类概念？

What is an abstract class? 包含一个或多个纯虚函数的类 Using abstract class 不能实例化抽象类 
但是可以定义抽象类的指针和引用 Converting abstract class to concrete class 定义一个抽象类的派生
类 定义所有纯虚函数

3.C++对抽象类具有以下限定

抽象类中含有纯虚函数，由于纯虚函数没有实现代码，所以不能建立抽象类的对象。
抽象类只能作为其他类的基类，可以通过抽象类对象的指针或引用访问到它的派生类对象，实现运行时的多态性。
如果派生类只是简单地继承了抽象类的纯虚函数，而没有重新定义基类的纯虚函数，则派生类也是一个抽象类。

*/

class Employee {
public:
	Employee(string name, string id);
	string getName();
	string getId();
	float getSalary();
	virtual void print();
private:
	string Name;
	string Id;
};
Employee::Employee(string name, string id) {
	Name = name;
	Id = id;
}
string Employee::getName() {
	return Name;
}
string Employee::getId() {
	return Id;
}
float Employee::getSalary() {
	return 0.0;
}
void Employee::print() {
	cout << "姓名：" << Name << "\t" << "编号：" << Id << endl;
}

class Manager :public Employee {
public:
	Manager(string name, string id, float s = 0.0) :Employee(name, id) {
		weeklySalary = s;
	}
	void setSalary(float s) { weeklySalary = s; }	//设置经理的周薪
	float getSalary() { return weeklySalary; }	//获取经理的周薪
	void print() {			//打印经理姓名、身份证、周薪
		cout << "经理：" << getName() << "\t\t 编号: " << getId() << "\t\t 周工资: " << getSalary() << endl;
	}
private:
	float weeklySalary; //周薪
};


/*
不论哪种赋值方式，都只能通过基类对象（或基类对象的指针或引用）访问到派生类对象从基类中继承到的成员，
不能借此访问派生类定义的成员。而虚函数使得可以通过基类对象的指针或引用访问派生类定义的成员。
*/
/**
int main() {
	Employee e("小米", "NO0001"), *pM;
	Manager m("小汪", "NO0002", 128);
	m.print();
	pM = &m;
	pM->print();
	Employee &rM = m;
	rM.print();
	system("pause");
	return 0;
}*/
/**
经理：小汪               编号: NO0002            周工资: 128
经理：小汪               编号: NO0002            周工资: 128
经理：小汪               编号: NO0002            周工资: 128

*/

//Virtual关键字其实质是告知编译系统，被指定为virtual的函数采用动态联编的形式编译。