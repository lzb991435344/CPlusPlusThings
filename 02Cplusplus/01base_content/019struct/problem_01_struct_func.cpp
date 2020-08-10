#include<stdio.h>

//C中struct
//(1)在C中struct只单纯的用作数据的复合类型，也就是说，在结构体声明中只能将数据成员放在里面，
//而不能将函数放在里面。
//(2)在C结构体声明中不能使用C++访问修饰符，如：public、protected、private 而在C++中可以使用。
//(3)在C中定义结构体变量，如果使用了下面定义必须加struct。
//(4)C的结构体不能继承（没有这一概念）。
//(5)若结构体的名字与函数名相同，可以正常运行且正常的调用！例如：可以定义与 struct Base 不
//冲突的 void Base() {}。

//全体成员默认是public的，class是private的
/**
struct Base {            // public
	int v1;
	//    public:      //error
	int v2;
	//private:
	int v3;
	//void print(){       // c中不能在结构体中嵌入函数
	//    printf("%s\n","hello world");
	//};    //error!
};*/

//与结构体名字相同
/*void Base() {
	printf("%s\n", "I am Base func");
}*/
//struct Base base1;  //ok
//Base base2; //error

/**
int main() {
	struct Base base;
	base.v1 = 1;
	//base.print();
	printf("%d\n", base.v1);
	Base();
	return 0;
}*/
/**
1
I am Base func
*/