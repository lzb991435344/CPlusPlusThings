#include <stdio.h> 

/**
1.volatile
	被 volatile 修饰的变量，在对其进行读写操作时，会引发一些可观测的副作用。
而这些可观测的副作用，是由程序之外的因素决定的。

2.volatile应用
（1）并行设备的硬件寄存器（如状态寄存器）。 假设要对一个设备进行初始化，此设备的
某一个寄存器为0xff800000。

int  *output = (unsigned  int *)0xff800000; //定义一个IO端口；
int   init(void)
{
	int i;
	for(i = 0; i< 10; i++)
	{
		*output = i;
	}
}
经过编译器优化后，编译器认为前面循环半天都是废话，对最后的结果毫无影响，因为最终
只是将output这个指针赋值为 9，所以编译器最后给你编译编译的代码结果相当于：

int  init(void)
{
	*output = 9;
}
	如果你对此外部设备进行初始化的过程是必须是像上面代码一样顺序的对其赋值，显然优化过程并
不能达到目的。反之如果你不是对此端口反复写操作，而是反复读操作，其结果是一样的，编译器
在优化后，也许你的代码对此地址的读操作只做了一次。然而从代码角度看是没有任何问题的。
这时候就该使用volatile通知编译器这个变量是一个不稳定的，在遇到此变量时候不要优化。

（2）一个中断服务子程序中访问到的变量；

static int i=0;

int main()
{
	while(1)
	{
		if(i) dosomething();
	}
}

// Interrupt service routine 
void IRS()
{
	i = 1;
}
	上面示例程序的本意是产生中断时，由中断服务子程序IRS响应中断，变更程序变量i，
使在main函数中调用dosomething函数，但是，由于编译器判断在main函数里面没有修
改过i，因此可能只执行一次对从i到某寄存器的读操作，然后每次if判断都只使用这
个寄存器里面的“i副本”，导致dosomething永远不会被调用。如果将变量i加上volatile修饰，
则编译器保证对变量i的读写操作都不会被优化，从而保证了变量i被外部程序更改后能及时在
原程序中得到感知。


（3）多线程应用中被多个任务共享的变量。 当多个线程共享某一个变量时，该变量的值会被某一个线程
更改，应该用 volatile 声明。作用是防止编译器优化把变量从内存装入CPU寄存器中，当一个线程更改变
量后，未及时同步到其它线程中导致程序出错。volatile的意思是让编译器每次操作该变量时一定要从内
存中真正取出，而不是使用已经存在寄存器中的值。

volatile  bool bStop = false;  //bStop 为共享全局变量
//第一个线程
void threadFunc1()
{
	...
	while(!bStop){...}
}
//第二个线程终止上面的线程循环
void threadFunc2()
{
	...
	bStop = true;
}

第二个线程终止第一个线程循环，如果bStop不使用volatile定义，那么这个
循环将是一个死循环，因为bStop已经读取到了寄存器中，寄存器中bStop的值
永远不会变成FALSE，加上volatile，程序在执行时，每次均从内存中读出bStop的
值，就不会死循环了。


3.volatile常见问题
（1）一个参数既可以是const还可以是volatile吗？为什么？ 可以。一个例子是只读的状态寄存器。
它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。

（2）一个指针可以是volatile吗？为什么？ 可以。尽管这并不常见。一个例子是当一个中断服务子程序修该
一个指向一个buffer的指针时。


4.volatile使用
(1)volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素
（操作系统、硬件、其它线程等）更改。所以使用 volatile 告诉编译器不应对这样的对象进行优化。

(2)volatile 关键字声明的变量，每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，
可能由于编译器的优化，从 CPU 寄存器中取值）

(3)const 可以是 volatile （如只读的状态寄存器）

(4)指针可以是 volatile

*/


/**
int main(void)
{
	const volatile int local = 10;
	int *ptr = (int*)&local;

	printf("Initial value of local : %d \n", local);

	*ptr = 100;

	printf("Modified value of local: %d \n", local);


	getchar();
	return 0;
}*/
/**
Initial value of local : 10
Modified value of local: 100
*/