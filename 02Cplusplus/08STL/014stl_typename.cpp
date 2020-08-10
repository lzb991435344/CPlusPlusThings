/**
typename
STL底层源码有下面几行,typedef与typename联用,这几个看着好复杂,究竟啥意思,我们今天一起来剖析!

template<typename _Iterator>
struct iterator_traits
{
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type        value_type;
  typedef typename _Iterator::difference_type   difference_type;
  typedef typename _Iterator::pointer           pointer;
  typedef typename _Iterator::reference         reference;
};
typename的常见用法
首先学习一下typename的常见用法:

template <typename T>
int compare(const T &a, const T &b)
{
	return a>b?a:b;
}
上述只是个案例程序,如果想写的比较完整比较大小,还得考虑特化版本,也许你会想
到上面这段代码中的typename换成class也一样可以，不错！



类作用域
在类外部访问类中的名称时，可以使用类作用域操作符，形如MyClass::name的调用通常存在三种：静态数据成员、静态成员函数和嵌套类型：

struct MyClass {
	static int A; //静态成员
	static int B(){cout<<"B()"<<endl; return 100;} //静态函数
	typedef int C;	//嵌套类型
	struct A1 {	//嵌套类型
		static int s;
	};
};
调用的时候,可以直接调:

cout<<MyClass::A<<endl;
cout<<MyClass::B()<<endl;
MyClass:C c;
...


让我们回到一个typename的例子:

template <class T>
void foo() {
	T::iterator * iter;
	// ...
}
这段代码的目的是什么？多数人第一反应可能是：作者想定义一个指针iter，它指向的类型是包含
在类作用域T中的iterator。可能存在这样一个包含iterator类型的结构：

struct MyIterator {
	struct iterator {

	};
};
调用如下:

foo<MyIterator>();

iter那行代码就很明显了，它是一个MyIterator::iterator类型的指针。我们猜测是这样的,现实是不是呢?

可是，如果是像T::iterator这样呢？T是模板中的类型参数，它只有等到模板实例化时才会知道是哪种类型，
更不用说内部的iterator。通过前面类作用域的介绍，

我们可以知道，T::iterator实际上可以是以下三种中的任何一种类型：

静态数据成员
静态成员函数
嵌套类型

前面例子中的ContainsAType::iterator是嵌套类型，完全没有问题。可如果是静态数据成员呢？如果实例
化foo模板函数的类型是像这样的：

struct MyIterator {
	static int iterator;
};
那么，T::iterator * iter;被编译器实例化为MyIterator::iterator * iter;，这是什么？前面是一个静态
成员变量而不是类型，那么这便成了一个乘法表达式，只不过iter在这里没有定义


typename
对于用于模板定义的依赖于模板参数的名称，只有在实例化的参数中存在这个类型名，或者这个名称前使用
了typename关键字来修饰，编译器才会将该名称当成是类型。除了以上这两种情况，绝不会被当成是类型。

因此，如果你想直接告诉编译器T::iterator是类型而不是变量，只需用typename修饰：

template <class T>
void foo() {
	//T::iterator是一个类型
	typename T::iterator * iter;
}
这样编译器就可以确定T::iterator是一个类型，而不再需要等到实例化时期才能确定，因此消除了前面提到的歧义。

剖析源码
回到STL源码

template<typename _Iterator>
struct iterator_traits
{
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type        value_type;
  typedef typename _Iterator::difference_type   difference_type;
  typedef typename _Iterator::pointer           pointer;
  typedef typename _Iterator::reference         reference;
};
看到上面的,我们就一下子清楚了,无非就是使用typename告诉编译器_Iterator::iterator_category是一个类
型,然后使用
typedef重命名一下,


*/