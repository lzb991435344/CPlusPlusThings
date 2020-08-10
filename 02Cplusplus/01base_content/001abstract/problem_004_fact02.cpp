#include<iostream> 
using namespace std;


/**
 * @brief 抽象类至少包含一个纯虚函数
 */
class Base
{
	int x;
public:
	Base() {
		cout<< "base"<<endl;
	}
	virtual void show() = 0;
	int getX() { return x; }

};
class Derived : public Base
{
public:
	void show() { cout << "In Derived \n"; }
	Derived() {
		cout << "derived" <<endl;
	}
};
/**
int main(void)
{
	//Base b;  //error! 不能创建抽象类的对象
	//Base *b = new Base(); error!
	Base *bp = new Derived(); // 抽象类的指针和引用 -> 由抽象类派生出来的类的对象
	bp->show();

	getchar();
	system("pause");
	return 0;
}*/
/**
base
derived
In Derived*/
