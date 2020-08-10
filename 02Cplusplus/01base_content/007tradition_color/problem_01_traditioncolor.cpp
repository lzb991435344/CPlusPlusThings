#include <iostream>
using namespace std;

//命名冲突
//enum Color { RED, BLUE };
enum Feeling { EXCITED, BLUE };

/**传统方式存在的问题

(1)作用域不受限,会容易引起命名冲突。例如下面无法编译通过的：
(2)会隐式转换为int
(3)用来表征枚举变量的实际类型不能明确指定，从而无法支持枚举类型的前向声明。

*/

/**
int main()
{
	getchar();
	return 0;
}*/