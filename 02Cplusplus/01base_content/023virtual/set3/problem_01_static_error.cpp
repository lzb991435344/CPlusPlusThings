/**
 * @file static_error.cpp
 * @brief 静态函数不可以声明为虚函数，同时也不能被const和volatile关键字修饰!
 * 原因如下：
 * static成员函数不属于任何类对象或类实例，所以即使给此函数加上virutal也是没有任何意义
 * 虚函数依靠vptr和vtable来处理。vptr是一个指针，在类的构造函数中创建生成，并且只能用this指针来访问它，
 静态成员函数没有this指针，所以无法访问vptr。
 */


//virtual static void fun() { }

//不属于类，所以没有this指针
//static void fun() const { }