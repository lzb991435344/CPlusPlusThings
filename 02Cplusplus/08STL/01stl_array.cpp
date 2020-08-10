
/**

1.std::tr1::array

#include <tr1/array>
std::tr1::array<int ,10> a;

tr1中的array比较简单，模拟语言本身的数组，并且让其支持迭代器操作，使其同其他容器一样，
能够调用算法。对于tr1中array没有构造与析构。迭代器是直接使用传递进来的类型定义指针。

简单的看一下这个静态数组array源码：

template<typename _Tp, std::size_t _Nm>
struct array
{
	typedef _Tp 	    			      value_type;
	typedef value_type&                   	      reference;
	typedef const value_type&             	      const_reference;
	typedef value_type*          		      iterator;
	typedef const value_type*			      const_iterator;
	typedef std::size_t                    	      size_type;
	typedef std::ptrdiff_t                   	   difference_type;
	typedef std::reverse_iterator<iterator>	      reverse_iterator;
	typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;
}
里面使用reverse_iterator作为rbegin与rend操作的迭代器。 看上去上面一个迭代器，
实际上两个，还有一个iterator,这个直接使用传递进来的类型定义指针，作为迭代器。

可以将其对比为vector中的正向与反向迭代器。

值得注意的是，在tr1::array中，支持传递数组大小为0，例如我们使用如下：

std::tr1::array<int,0> a;
对于这样的写法，会对应到下面：

// Support for zero-sized arrays mandatory.
value_type _M_instance[_Nm ? _Nm : 1];
根据传递进来的大小，如果不为0，就是传递进来的大小，否则为1。



2.std::array

2.std::array
使用

std::array<int ,10> a;
std中的array包含了

对比tr1与std的array

template<typename _Tp, std::size_t _Nm>
struct array
{
	typedef _Tp 	    			      value_type;
	typedef value_type*			      pointer;
	typedef const value_type*                       const_pointer;
	typedef value_type&                   	      reference;
	typedef const value_type&             	      const_reference;
	typedef value_type*          		      iterator;
	typedef const value_type*			      const_iterator;
	typedef std::size_t                    	      size_type;
	typedef std::ptrdiff_t                   	      difference_type;
	typedef std::reverse_iterator<iterator>	      reverse_iterator;
	typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

	// Support for zero-sized arrays mandatory.
	typedef _GLIBCXX_STD_C::__array_traits<_Tp, _Nm> _AT_Type;    // # define _GLIBCXX_STD_C std
	typename _AT_Type::_Type                         _M_elems;
}
发现array里面有两处值得注意的地方：

// Support for zero-sized arrays mandatory.
typedef _GLIBCXX_STD_C::__array_traits<_Tp, _Nm> _AT_Type;    // # define _GLIBCXX_STD_C std
typename _AT_Type::_Type                         _M_elems;

在源码中去找__array_traits，看到：

template<typename _Tp, std::size_t _Nm>
struct __array_traits
{
	typedef _Tp _Type[_Nm];

	static constexpr _Tp&
	_S_ref(const _Type& __t, std::size_t __n) noexcept
	{ return const_cast<_Tp&>(__t[__n]); }
};
上面两行的代码可以理解为下面：

typedef _Tp _Type[100];
typedef _Type _M_elems;  // 一个含有100个元素的数组。
在实际写代码的时候，如果要定义一个数组，我们可以这样写：

int a[100];
//或者
typedef int T[100];
typedef T a;
针对传进来的size处理，相比于tr1，更加复杂，使用了模板偏特化来处理传递size为0情况。

template<typename _Tp, std::size_t _Nm>
struct __array_traits
{
	typedef _Tp _Type[_Nm];

	static constexpr _Tp&
	_S_ref(const _Type& __t, std::size_t __n) noexcept
	{ return const_cast<_Tp&>(__t[__n]); }
};

template<typename _Tp>
struct __array_traits<_Tp, 0>
{
	struct _Type { };

	static constexpr _Tp&
	_S_ref(const _Type&, std::size_t) noexcept
	{ return *static_cast<_Tp*>(nullptr); }
};



*/

#include <array>
#include <iostream>

/**
int main() {

	std::array<int, 10> arr = {1,2,3,4,5};

	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; ++i) {
		std::cout << arr[i];
	}
	return 0;
}
*/
/*
1234500000

*/




