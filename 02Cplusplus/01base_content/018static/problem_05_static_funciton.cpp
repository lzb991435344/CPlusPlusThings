#include<iostream> 
using namespace std;

class Apple
{
public:
	// static member function 
	//静态成员函数也不依赖于类的对象。我们被允许使用对象和'.'来调用静态成员函数。
	//但建议使用类名和范围解析运算符调用静态成员。

	//允许静态成员函数仅访问静态数据成员或其他静态成员函数，它们无法访问类的非
	//静态数据成员或成员函数。
	static void printMsg()
	{
		cout << "Welcome to Apple!";
	}
};

// main function 
/**
int main()
{
	// invoking a static member function 
	Apple::printMsg();
	return 0;
}*/
/**
Welcome to Apple!

*/
