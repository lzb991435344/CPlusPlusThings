#include<iostream>
#include<stdio.h>

struct Base {
	int v1;
	//    private:   //error!
	int v3;
public:     //显示声明public
	int v2;
	void print() {
		printf("%s\n", "hello world");
	};
};

typedef struct Base1 {
	int v1;
	//    private:   //error!
	int v3;
public:     //显示声明public
	int v2;
	void print() {
		printf("%s\n", "hello world");
	};
}B;

void Base() {
	printf("%s\n", "I am Base func");
}
//void B() {}  //error! 符号 "B" 已经被定义为一个 "struct Base1" 的别名
/**
int main() {
	struct Base base;  //ok
	//B bs;//ok

	//同名的只能带结构体struct,否则出错
	//Base base1;  // error!
	base.v1 = 1;
	base.v3 = 2;
	base.print();
	printf("%d\n", base.v1);
	printf("%d\n", base.v3);
	Base();
	return 0;
}*/

/**
hello world
1
2
I am Base func
*/