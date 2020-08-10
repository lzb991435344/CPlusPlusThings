/*
使用前向引用声明虽然可以解决一些问题，但它并不是万能的。需要注意的是，
尽管使用了前向引用声明，但是在提供一个完整的类声明之前，不能声明该类的对象，
也不能在内联成员函数中使用该类的对象。请看下面的程序段：
*/
/**
//第一种
//#include<iostream>
class Fred1;	//前向引用声明
class Barney1 {
	Fred1 x;	//错误：类Fred的声明尚不完善
};
class Fred1 {
	Barney1 y;
};


//第二种
class Fred2;	//前向引用声明

class Barney2 {
public:
	void method()
	{
		x->yabbaDabbaDo();	//错误：Fred类的对象在定义之前被使用
	}
private:
	Fred2* x;   //正确，经过前向引用声明，可以声明Fred类的对象指针
};

class Fred2 {
public:
	void yabbaDabbaDo();
private:
	Barney2* y;
};*/

/*
总结：当使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节。
*/