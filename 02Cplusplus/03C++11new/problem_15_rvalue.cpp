#include <iostream>
#include <complex>
#include <vector>

using namespace std;

/**
// Rvalue references 解决非必要的拷贝  当赋值右手边是一个"右值",左手边对象可以偷右手边对象,
//而不需要重新分配内存。
// 浅copy
int foo() { return 5; }

class Foo {
public:
	//=default: 用于显式要求编译器提供合成版本的四大函数(构造、拷贝、析构、赋值)
	//=delete可以告知编译器，不生成默认的这些成员。
	//1、=delete可以使用在任意的函数上(可以引导函数匹配过程)，除了析构函数(析构函数为删除函数将 
	//导致该类型无法销毁);=default必须用在有默认合成函数的函数上。 
	//2、=delete必须出现在函数第一次声明的时候。

	Foo() = default;

	Foo(const Foo &foo) = default;
	

	//基本的异常处理方式
	//1.Foo(Foo &foo)  throw(){}    C++11之前
	//2.Foo(Foo &foo) noexcept {}   C++11之后
	
	Foo(Foo &&foo) noexcept {}
};


// 判断调用哪一个函数
void process(int &i) {
	cout << "左值传入" << endl;
}

void process(int &&i) {
	cout << "右值传入" << endl;
}

void UnPerfectForward(int &&i) {
	cout << "forward(int&& i)" << endl;
	process(i);
}
// std::forward()实现就是下面这样
void PerfectForward(int &&i) {
	cout << "forward(int&& i)" << endl;
	process(static_cast<int&&>(i));
}
// Lvalue: 变量
// Rvalue: 临时对象就是个右值,右值不可以放在左边
int main() {
	int a = 9, b = 4;

	a = b;
	b = a;
	//    a+b=42;// error Rvalue

	string s1("hello");
	string s2("world");
	s1 + s2 = s2;   // ok
	string() = "ok";  // ok

	cout << "s2:" << s1 + s2 << endl;
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;

	complex<int> c1(3, 8), c2(1, 0);
	c1 + c2 = complex<int>(3, 4);   // ok
	complex<int>() = complex<int>(1, 2); // ok

	int x = foo();
	//    int *p=&foo(); //error!  Rvalue不可以取地址
	//    foo()=7;  // error
		// Rvalue references
	//    vector<Foo> vec;
	//    vec.insert(vec.begin(), Foo());  // Rvalue references and Move Semantics
		//  原先是下面这个
		//  iterator insert(const_iterator __position, const value_type& __x);
		// 调用下面这个Move Semantics
		//  iterator insert(const_iterator __position, value_type&& __x)        // 然后转交给Foo(Foo&& foo)
		//  { return emplace(__position, std::move(__x)); }
		// Foo()这个临时对象为右值交给insert的move assignment然后再交给Foo的move ctor。中间有可能会丢失一些信息。

	int aa = 1;
	process(aa);            // L
	process(1);             // R
	process(move(aa));      // R

	UnPerfectForward(2); // 希望通过转交调用的是右值传入函数,可是调用的是左值传入 这就是个Unperfect Forwarding
	UnPerfectForward(move(aa));  // 同上
	// 那如何设计Perfect Forwarding?
	// 为传递加上static_cast<int &&>强转或者直接使用std::forward()
	PerfectForward(2);
	PerfectForward(move(aa));

	return 0;
}*/
/**
s2:helloworld
s1:hello
s2:world
左值传入
右值传入
右值传入
forward(int&& i)
左值传入
forward(int&& i)
左值传入
forward(int&& i)
右值传入
forward(int&& i)
右值传入
*/