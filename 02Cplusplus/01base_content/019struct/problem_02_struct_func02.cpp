#include<iostream>
#include<stdio.h>
/**
(1)C++结构体中不仅可以定义数据，还可以定义函数。
(2)C++结构体中可以使用访问修饰符，如：public、protected、private 。
(3)C++结构体使用可以直接使用不带struct。
(4)C++继承
若结构体的名字与函数名相同，可以正常运行且正常的调用！但是定义结构体变量时候只用用带struct的！

*/

//C++中的struct
struct Base {
	int v1;
	//    private:   //error!
	int v3;
public:     //显示声明public
	int v2;
	//可以定义函数
	void print() {
		printf("%s\n", "hello world");
	};
};

/**
int main() {
	struct Base base1;  //ok
	Base base2; //ok
	Base base;
	base.v1 = 1;
	base.v3 = 2;
	base.print();
	printf("%d\n", base.v1);
	printf("%d\n", base.v3);
	return 0;
}*/
/**
hello world
1
2

*/