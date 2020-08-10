#include<iostream>
using namespace std;

/**
 * @brief 定义了一个变量pFun，这个变量是个指针，指向返回值和参数都是空的函数的指针！
 */
void (*pFun)(int);

/**
 * @brief 代表一种新类型，不是变量！所以与上述的pFun不一样！
 */

//定义新类型
typedef void (*func)(void);

void myfunc(void)
{
	cout << "asda" << endl;
}

void glFun(int a) {
	cout << a << endl;
}
/**
int main() {
	//定义新类型 
	func pfun = myfunc;//赋值
	pfun(); //调用

	//函数指针赋值
	pFun = glFun;
	(*pFun)(2);

	return 0;
}*/
/*

asda
2

*/