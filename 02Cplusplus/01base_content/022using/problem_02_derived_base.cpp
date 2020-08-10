#include <iostream>

using namespace std;

/**
class Base{
public:
	 std::size_t size() const { return n;  }
protected:
	std::size_t n;
};
class Derived : private Base {
public:
	using Base::size;
protected:
	using Base::n;
};
*/

//类Derived私有继承了Base，对于它来说成员变量n和成员函数size都是私有的，如果
//使用了using语句，可以改变他们的可访问性，如上述例子中，size可以按public的权限访问，
//n可以按protected的权限访问。

class Base1 {
public:
	Base1() :value(10) {}
	virtual ~Base1() {}
	void test1() { cout << "Base test1..." << endl; }
protected: // 保护
	int value;
};
// 默认为私有继承
class Derived1 : Base1 {
public:
	void test2() { cout << "value is " << value << endl; }
};

class Base {
public:
	Base() :value(20) {}
	virtual ~Base() {}
	void test1() { cout << "Base test1..." << endl; }
//private:  //私有
	int value; //private不可访问
};

/**
 * 子类对父类成员的访问权限跟如何继承没有任何关系，
 * “子类可以访问父类的public和protected成员，不可以访问父类的private成员”——
 //这句话对任何一种继承都是成立的。
 *
 */
class Derived : Base {
public:
	using Base::value;
	void test2() { cout << "value is " << value << endl; }
};

/**
int main()
{
	Derived1 d1;
	d1.test2();

	Derived d;
	d.test2();
	return 0;
}*/
/**
value is 10
value is 20

*/