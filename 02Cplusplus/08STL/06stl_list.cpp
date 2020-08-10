/**
1.list
	list为双向环形链表，双向环状链表从节点值为3开始插入，红色框表示最后一个节点(end()指向的节点)。
黄色线条表示指向前驱节点，黑色线条表示指向后继节点。

1.1 list源码
1.1.1 类结构
 template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
 class list : protected _List_base<_Tp, _Alloc>
 {
 }
list继承_List_base。


1.1.2 双向环形链表实现
【构造函数】
（1）不带任何元素的list

explicit
list(const allocator_type &__a) _GLIBCXX_NOEXCEPT: _Base(_Node_alloc_type(__a)) {}


（2）带n个元素且赋予初值的list

explicit list(size_type __n, const value_type &__value = value_type(),const allocator_type &__a = allocator_type()) : _Base(_Node_alloc_type(__a))
{ _M_fill_initialize(__n, __value); }


（3）从一个范围中进行初始化list
template<typename _InputIterator>
list(_InputIterator __first, _InputIterator __last,
	 const allocator_type &__a = allocator_type())
		: _Base(_Node_alloc_type(__a)) {
	// Check whether it's an integral type.  If so, it's not an iterator.
	typedef typename std::__is_integer<_InputIterator>::__type _Integral;
	_M_initialize_dispatch(__first, __last, _Integral());
}



一：【创建节点】

做的事情：创建一个新的节点并动态分配内存，返回节点。

_Node * _M_create_node(const value_type &__x) {
	_Node *__p = this->_M_get_node();
	__try
	{
		_M_get_Tp_allocator().construct
				(std::__addressof(__p->_M_data), __x);
	}
	__catch(...)
	{
		_M_put_node(__p);
		__throw_exception_again;
	}
	return __p;
}
注意到里面有两个重要的函数_M_get_node与_M_put_node，我们来查看后发现这些方法来自基类，源码为：

_List_node<_Tp> * _M_get_node() { return _M_impl._Node_alloc_type::allocate(1); }

void _M_put_node(_List_node<_Tp> *__p)   _GLIBCXX_NOEXCEPT
{ _M_impl._Node_alloc_type::deallocate(__p, 1); }
对应的就是创建节点动态分配内存，若创建过程中抛出异常，则释放内存。



二：【插入节点】
a.尾部插入n个指定节点值的节点，对应的函数_M_fill_initialize

在list的构造函数中使用：

explicit list(size_type __n, const value_type &__value = value_type(),const allocator_type &__a = allocator_type()) : _Base(_Node_alloc_type(__a))
{ _M_fill_initialize(__n, __value); }



b.指定位置插入指定节点值的节点，对应的函数_M_insert
其中大家经常使用的push_back与push_front底层就是调用_M_insert函数。


两者函数区别是：
this->_M_insert(end(), __x);  // push_back   尾部插入
this->_M_insert(begin(), __x); // push_front 头部插入


双向环形链表插入函数_M_hook (最重要！！！)

其中_M_fill_initialize源码如下：

void _M_fill_initialize(size_type __n, const value_type &__x) {
	for (; __n; --__n)
		push_back(__x);
}
其中push_back源码如下：

void push_back(const value_type &__x) { this->_M_insert(end(), __x); }
其中_M_insert，在指定的位置插入初始值为x的节点。

void _M_insert(iterator __position, const value_type &__x) {
	_Node *__tmp = _M_create_node(__x);
	__tmp->_M_hook(__position._M_node);
}
其中_M_hook实现在gcc-4.9.1/libstdc++-v3/src/c++98/list.cc中,当然_List_node_base的其他函数，
例如：_M_unhook也在这个文件中。

// 在指定的位置前插入this指向的节点
void_List_node_base::_M_hook(_List_node_base* const __position) _GLIBCXX_USE_NOEXCEPT
{
  this->_M_next = __position;
  this->_M_prev = __position->_M_prev;
  __position->_M_prev->_M_next = this;
 }

 （1）在指定的位置插入初始值为x的节点
void _M_insert(iterator __position, const value_type &__x) {
	_Node *__tmp = _M_create_node(__x);
	__tmp->_M_next = __position;			// 第一步
	__tmp->_M_prev = __position->_M_prev;	// 第二步
	__position->_M_prev->_M_next = __tmp;	// 第三步
	__position->_M_prev = __tmp;			// 第四步
}
这种插入是在指定位置前插入，(对应到代码就是)例如实现在指定__position节点为7前插入节点
值9的节点(对应到代码就是__tmp)，下面阐述了具体的插入流程。

 （2）在末尾依次插入n个节点值为x的节点
  void _M_fill_initialize(size_type __n, const value_type &__x) {
	for (; __n; --__n)
		_M_insert(end(), __x);
}
对于上述的代码大家或许会联想到insert,它有三个。insert实现文件在libstdc++-v3/include/bits/list.tcc。


第一：在指定迭代器之前插入指定元素值节点。
实现是调用前面的_M_hook函数。

template<typename _Tp, typename _Alloc>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::
#if __cplusplus >= 201103L
insert(const_iterator __position, const value_type& __x)
#else
insert(iterator __position, const value_type& __x)
#endif
{
  _Node* __tmp = _M_create_node(__x);
  __tmp->_M_hook(__position._M_const_cast()._M_node);
  return iterator(__tmp);
}

第二：在指定迭代器之前插入n个指定节点值的节点。
void insert(iterator __position, size_type __n, const value_type &__x) {
	list __tmp(__n, __x, get_allocator());
	splice(__position, __tmp);
}
实现是先调用list构造函数，完成创建一个拥有n个指定节点值的list。

explicit list(size_type __n, const value_type &__value = value_type(),const allocator_type &__a = allocator_type()) : _Base(_Node_alloc_type(__a))
{ _M_fill_initialize(__n, __value); }
然后使用splice函数完成从另一个list中来插入当前list。

void splice(iterator __position, list &__x)
{
	if (!__x.empty()) {
		_M_check_equal_allocators(__x);

		this->_M_transfer(__position._M_const_cast(),
						  __x.begin(), __x.end());
	}
}
其中_M_transfer追踪代码，可以知道：

// Moves the elements from [first,last) before position.
void
_M_transfer(iterator __position, iterator __first, iterator __last) {
	__position._M_node->_M_transfer(__first._M_node, __last._M_node);
}
再次分析得到其来自list的基类_List_node_base，而_M_transfer实现文件在gcc-4.9.1
/libstdc++-v3/src/c++98/list.cc中：

void _List_node_base::
_M_transfer(_List_node_base * const __first,
	_List_node_base * const __last) _GLIBCXX_USE_NOEXCEPT
{
  if (this != __last)
  {
	  // Remove [first, last) from its old position.
	  __last->_M_prev->_M_next  = this;
	  __first->_M_prev->_M_next = __last;
	  this->_M_prev->_M_next    = __first;

	  // Splice [first, last) into its new position.
	  _List_node_base* const __tmp = this->_M_prev;
	  this->_M_prev                = __last->_M_prev;
	  __last->_M_prev              = __first->_M_prev;
	  __first->_M_prev             = __tmp;
  }
}


实现是先调用list构造函数，完成创建一个拥有n个指定节点值的list。

explicit list(size_type __n, const value_type &__value = value_type(),const allocator_type &__a = allocator_type()) : _Base(_Node_alloc_type(__a))
{ _M_fill_initialize(__n, __value); }
然后使用splice函数完成从另一个list中来插入当前list。

void splice(iterator __position, list &__x)
{
	if (!__x.empty()) {
		_M_check_equal_allocators(__x);

		this->_M_transfer(__position._M_const_cast(),
						  __x.begin(), __x.end());
	}
}
其中_M_transfer追踪代码，可以知道：

// Moves the elements from [first,last) before position.
void
_M_transfer(iterator __position, iterator __first, iterator __last) {
	__position._M_node->_M_transfer(__first._M_node, __last._M_node);
}
再次分析得到其来自list的基类_List_node_base，而_M_transfer实现文件在gcc-4.9.1/
libstdc++-v3/src/c++98/list.cc中：

void _List_node_base::
_M_transfer(_List_node_base * const __first,
	_List_node_base * const __last) _GLIBCXX_USE_NOEXCEPT
{
  if (this != __last)
  {
	  // Remove [first, last) from its old position.
	  __last->_M_prev->_M_next  = this;
	  __first->_M_prev->_M_next = __last;
	  this->_M_prev->_M_next    = __first;

	  // Splice [first, last) into its new position.
	  _List_node_base* const __tmp = this->_M_prev;
	  this->_M_prev                = __last->_M_prev;
	  __last->_M_prev              = __first->_M_prev;
	  __first->_M_prev             = __tmp;
  }
}







2.list's Iterator剖析

2.1 iterator
list的iterator定义

template<typename _Tp>
struct _List_iterator
{
  typedef _List_iterator<_Tp>                _Self;
  typedef _List_node<_Tp>                    _Node;

  typedef ptrdiff_t                          difference_type;
  typedef std::bidirectional_iterator_tag    iterator_category;
  typedef _Tp                                value_type;
  typedef _Tp*                               pointer;
  typedef _Tp&                               reference;

   // The only member points to the %list element.
   __detail::_List_node_base* _M_node;
   //  _List_node(节点的数据部分) -> _List_node_base(前指针与后指针)

  _List_iterator() _GLIBCXX_NOEXCEPT
  : _M_node() { }

  explicit
  _List_iterator(__detail::_List_node_base* __x) _GLIBCXX_NOEXCEPT
  : _M_node(__x) { }

  _Self
  _M_const_cast() const _GLIBCXX_NOEXCEPT
  { return *this; }

  // The only member points to the %list element.
  __detail::_List_node_base* _M_node;
};
内部重载函数:

// Must downcast from _List_node_base to _List_node to get to _M_data.
// 重载*操作符
reference operator*() const _GLIBCXX_NOEXCEPT
{
	return static_cast<_Node*>(_M_node)->_M_data;
}

// 重载->操作符
pointer operator->() const _GLIBCXX_NOEXCEPT
{
	return std::__addressof(static_cast<_Node*>(_M_node)->_M_data);
}

// 重载前置++操作符  ++i
_Self& operator++() _GLIBCXX_NOEXCEPT
{
	_M_node = _M_node->_M_next;
	return *this;
}

// 重载后置++操作符 i++
_Self operator++(int) _GLIBCXX_NOEXCEPT
{
	_Self __tmp = *this;			 // 记录原值  *调用的是拷贝构造函数
	_M_node = _M_node->_M_next;		 // 进行操作
	return __tmp;					 // 返回原值
}

// 重载前置--操作符  --i
_Self& operator--() _GLIBCXX_NOEXCEPT
{
	_M_node = _M_node->_M_prev;
	return *this;
}
// 重载后置--操作符  --i
_Self operator--(int) _GLIBCXX_NOEXCEPT
{
	_Self __tmp = *this;
	_M_node = _M_node->_M_prev;
	return __tmp;
}
// 重载++操作符
bool operator==(const _Self& __x) const _GLIBCXX_NOEXCEPT
{
	return _M_node == __x._M_node;
}
// 重载!=操作符
bool operator!=(const _Self& __x) const _GLIBCXX_NOEXCEPT
{
	return _M_node != __x._M_node;
}


2.2 结点设计
iterator内部的_List_node,这里可以得到继承自_List_node_base.

_List_node放数据部分
_List_node_base放前后指针

/// An actual node in the %list.
template<typename _Tp>
struct _List_node : public __detail::_List_node_base
{
  ///< User's data.
  _Tp _M_data;

#if __cplusplus >= 201103L
  template<typename... _Args>
	_List_node(_Args&&... __args)
: __detail::_List_node_base(), _M_data(std::forward<_Args>(__args)...)
	{ }
#endif
};
_List_node_base代码:

namespace __detail
{
	_GLIBCXX_BEGIN_NAMESPACE_VERSION
	/// Common part of a node in the %list.
	struct _List_node_base
	{
	  _List_node_base* _M_next;
	  _List_node_base* _M_prev;

	  static void
	  swap(_List_node_base& __x, _List_node_base& __y) _GLIBCXX_USE_NOEXCEPT;

	  void
	  _M_transfer(_List_node_base* const __first,
		  _List_node_base* const __last) _GLIBCXX_USE_NOEXCEPT;

	  void
	  _M_reverse() _GLIBCXX_USE_NOEXCEPT;

	  void
	  _M_hook(_List_node_base* const __position) _GLIBCXX_USE_NOEXCEPT;

	  void
	  _M_unhook() _GLIBCXX_USE_NOEXCEPT;
	};

	_GLIBCXX_END_NAMESPACE_VERSION
} // namespace detail
迭代器在设计的时候,总是保持前闭后开原则,例如iter->begin()指向第一个元素,iter->end()指向实际
最后一个元素的下一个元素,故最后的设计刻意在环形list尾部加一个空白结点,用以符合STL前闭后开原则.




*/