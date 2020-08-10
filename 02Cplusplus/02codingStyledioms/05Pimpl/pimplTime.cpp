#include <iostream>
#include <vector>
using namespace std;

class C {
	vector<int> v;
	string s;
};
class D {
	string s;
};

class X {
private:
	struct XImpl;
	XImpl* pImpl;
};

struct X::XImpl {
	C c;
	D d;
};
/**
(1)二进制兼容性
开发库时，可以在不破坏与客户端的二进制兼容性的情况下向XImpl添加/修改字段（这将导致崩溃！）。 
由于在向Ximpl类添加新字段时X类的二进制布局不会更改，因此可以安全地在次要版本更新中向库添加新功能。

当然，您也可以在不破坏二进制兼容性的情况下向X / XImpl添加新的公共/私有非虚拟方法，但这与标准的标
头/实现技术相当。

(2)数据隐藏
如果您正在开发一个库，尤其是专有库，则可能不希望公开用于实现库公共接口的其他库/实现技术。 要么是
由于知识产权问题，要么是因为您认为用户可能会被诱使对实现进行危险的假设，或者只是通过使用可怕的转换技巧来破坏封装。 PIMPL解决/缓解了这一难题。

(3)编译时间
编译时间减少了，因为当您向XImpl类添加/删除字段和/或方法时（仅映射到标准技术中添加私有字段/方法的情况），
仅需要重建X的源（实现）文件。 实际上，这是一种常见的操作。

使用标准的标头/实现技术（没有PIMPL），当您向X添加新字段时，曾经重新分配X（在堆栈或堆上）的每个客户端
都需要重新编译，因为它必须调整分配的大小 。 好吧，每个从未分配X的客户端也都需要重新编译，但这只是开
销（客户端上的结果代码是相同的）

*/

/**
int main() {
	X x;
}*/