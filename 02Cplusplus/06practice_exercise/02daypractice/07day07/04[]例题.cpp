#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct Person {                		//职工基本信息的结构
	double salary;
	char *name;
};
class SalaryManaege {
	Person *employ;          	 //存放职工信息的数组
	int max;                  		//数组下标上界
	int n;                    		//数组中的实际职工人数
public:
	SalaryManaege(int Max = 0) {
		max = Max;
		n = 0;
		employ = new Person[max];
	}
	double &operator[](char *Name) {       	//重载[]，返回引用
		Person *p;
		for (p = employ; p < employ + n; p++)
			//如果存在处理   	
			if (strcmp(p->name, Name) == 0)
				return p->salary;
		//不存在情况处理
		p = employ + n++;
		p->name = new char[strlen(Name) + 1];
		strcpy(p->name, Name);
		p->salary = 0;
		return p->salary;
	}

	void display() {
		for (int i = 0; i < n; i++)
			cout << employ[i].name << "   " << employ[i].salary << endl;
	}
};
/**
int main() {
	SalaryManaege s(3);
	s["张三"] = 2188.88;
	s["里斯"] = 1230.07;
	s["王无"] = 3200.97;
	cout << "张三\t" << s["张三"] << endl;          cout << "里斯\t" << s["里斯"] << endl;
	cout << "王无\t" << s["王无"] << endl;

	cout << "-------下为display的输出--------\n\n";
	s.display();
	system("pause");
}*/
/**
四、重载赋值运算符[]

1、[ ]是一个二元运算符，其重载形式如下：

class X{
……
		X& operator[](int n);
};
2、重载[]需要注意的问题

[]是一个二元运算符，其第1个参数是通过对象的this指针传递的，第2个参数代表数组的下标
由于[]既可以出现在赋值符“=”的左边，也可以出现在赋值符“=”的右边，所以重载运算符[]时常返回引用。
[]只能被重载为类的非静态成员函数，不能被重载为友元和普通函数。


**/