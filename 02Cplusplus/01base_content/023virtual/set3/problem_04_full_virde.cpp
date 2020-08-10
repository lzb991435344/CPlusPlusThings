/**
 * @file full_virde.cpp
 * @brief 将基类的析构函数声明为虚函数
 * 输出结果：
 *      Constructing base
 *      Constructing derived
 *      Destructing derived
 *      Destructing base
 */
#include<iostream> 

using namespace std;

class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	virtual ~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};
/**
int main(void)
{
	derived *d = new derived();
	base *b = d;
	delete b;
	return 0;
}
/**
Constructing base
Constructing derived
Destructing derived
Destructing base
*/