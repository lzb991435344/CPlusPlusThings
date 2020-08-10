#include <iostream>
using namespace std;

/**
五、重载( )

1、运算符( )是函数调用运算符，也能被重载。且只能被重载为类的成员函数。

2、运算符( )的重载形式如下：

class X{
……
		X& operator( )(参数表);
}；
其中的参数表可以包括任意多个参数。

3、运算符( )的调用形式如下：

X Obj; //对象定义

Obj()(参数表); //调用形式1

Obj(参数表); //调用形式2

*/

class Time {
private:
	int hh, mm, ss;
public:
	Time(int h = 0, int m = 0, int s = 0) :hh(h), mm(m), ss(s) {}
	void operator()(int h, int m, int s) {
		hh = h;
		mm = m;
		ss = s;
	}
	void ShowTime() {
		cout << hh << ":" << mm << ":" << ss << endl;
	}
};
/**
int main() {
	Time t1(12, 10, 11);
	t1.ShowTime();
	t1.operator()(23, 20, 34);
	t1.ShowTime();
	t1(10, 10, 10);
	t1.ShowTime();
	system("pause");
}*/
/**
12:10:11
23:20:34
10:10:10

*/