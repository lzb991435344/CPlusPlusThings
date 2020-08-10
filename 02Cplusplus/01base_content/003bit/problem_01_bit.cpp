#include<iostream>

using namespace std;
struct stuff
{
	unsigned int field1 : 30;
	unsigned int : 2;
	unsigned int field2 : 4;
	unsigned int : 0;
	unsigned int field3 : 3;
};

struct box {
	unsigned int ready : 2;
	unsigned int error : 2;
	unsigned int command : 4;
	unsigned int sector_no : 24;
}b1;

//x86 系统中 unsigned int 和 box 都为 32 Bits,通过该联合使 st_box 和 ui_box 共享一块内存
union u_box {
	struct box st_box;
	unsigned int ui_box;
};
/**
int main() {
	struct stuff s = { 1,3,5 };
	cout << s.field1 << endl;
	cout << s.field2 << endl;
	cout << s.field3 << endl;
	cout << sizeof(s) << endl;

	//具体位域中哪一位与 unsigned int 哪一位相对应，取决于编译器和硬件。 利用联合将位域归零
	union u_box u;
	u.ui_box = 0;

	getchar();
	return 0;
}*/

/**
1
3
5
12

*/


/**
struct stuff
{
	unsigned int field1: 30;
	unsigned int field2: 4;
	unsigned int field3: 3;
};

field1 + field2 = 34 Bits，超出 32 Bits, 编译器会将field2移位至下一个 unsigned int 单元存放，
stuff.field1 和 stuff.field2 之间会留下一个 2 Bits 的空隙， stuff.field3 紧跟在 stuff.field2 之后，
该结构现在大小为 2 * 32 = 64 Bits。

这个空洞可以用之前提到的未命名的位域成员填充，我们也可以使用一个宽度为 0 的未命名位域成员令下一位域
成员与下一个整数对齐。 例如:

struct stuff
{
	unsigned int field1: 30;
	unsigned int       : 2;
	unsigned int field2: 4;
	unsigned int       : 0;
	unsigned int field3: 3;
};
这里 stuff.field1 与 stuff.field2 之间有一个 2 Bits 的空隙，stuff.field3 则存储在下一个 unsigned int 中，
该结构现在大小为 3 * 32 = 96 Bits。



初始化
位域的初始化与普通结构体初始化的方法相同，这里列举两种，如下:

struct stuff s1= {20,8,6};
或者直接为位域成员赋值

struct stuff s1;
s1.field1 = 20;
s1.field2 = 8;
s1.field3 = 4;
位域的重映射 (Re-mapping)
声明一个 大小为 32 Bits 的位域

struct box {
	unsigned int ready:     2;
	unsigned int error:     2;
	unsigned int command:   4;
	unsigned int sector_no: 24;
}b1;

利用重映射将位域归零
int* p = (int *) &b1;  // 将 "位域结构体的地址" 映射至 "整形（int*) 的地址"
*p = 0;                // 清除 s1，将各成员归零

利用联合 (union) 将 32 Bits 位域 重映射至 unsigned int 型
我们可以声明以下联合:

union u_box {
  struct box st_box;
  unsigned int ui_box;
};
x86 系统中 unsigned int 和 box 都为 32 Bits, 通过该联合使 st_box 和 ui_box 共享一块内存。
具体位域中哪一位与 unsigned int 哪一位相对应，取决于编译器和硬件。 利用联合将位域归零，代码如下：

union u_box u;
u.ui_box = 0;

*/