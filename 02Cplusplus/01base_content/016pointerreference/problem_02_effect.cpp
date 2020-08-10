#include<iostream>
using namespace std;

//拷贝构造函数为什么参数是引用?
/**
复制构造函数，其bai实也du是一个函数，如果你给它定义的参数，是一个类型，而不是一个类型的引用，
它会首先调用该类型的复制构造函数，重新构造一个新的实例，就像下面一个例子

class myclass {

};
int fun(myclass a); // 这是一个函数

当你调用它时，编译器会自动调用 myclass 类型的构造函数，重新实例化一个myclass的实例

int fun(myclass &a) //这个函数，就不会调用myclass类型的构造函数，只是传递一个指针
好了~现在回到你的问题，赋值构造函数也是构造函数的一种，你给它一个非引用，非指针的参数，它一定会调
用该类型的构造函数
这下好了~一个函数不断的调用自己，这样能不出错，能不堆栈溢出么？
简化起来，事情就像这个样子
int fun(myclass a)
{
fun(a);
}
*/

/**
	指针和引用在汇编层上的操作是一样的,性能上差别不大

*/


void test1(int* p)
{
	//可以改变形参的值
	*p = 3;    //此处应该首先判断p是否为空，为了测试的需要，此处我们没加。
	return;
}

void test2(int& p)
{
	p = 3;    //此处应该首先判断p是否为空，为了测试的需要，此处我们没加。
	return;
}

/**
int main() {
	int a = 10;
	int *p = &a;
	test1(p);
	cout << *p << endl;

	test2(a);
	cout << a << endl;
	return 0;
}*/
/**
3
3
*/