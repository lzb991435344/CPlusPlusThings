#include<iostream>
#include<stdio.h>


struct Base {
	int v1;
	//    private:   //error!
	int v3;
public:   //显示声明public
	int v2;
	 virtual void print() {
		printf("%s\n", "Base");
	};
};
struct Derived :Base {

public:
	int v2;
	 void print() {
		printf("%s\n", "Derived");
	};
};

class A {
public:
	virtual void ss() {
		std::cout<< "i am from A"<<std::endl;
	}
};
class B :public A {
public:
	virtual  void ss() {
		std::cout << "i am from B" << std::endl;
	}
};

/**
int main() {
	Base *b = new Derived();
	b->print();

	A* bs = new B();
	bs->ss();

	return 0;
}*/
/*
Derived
i am from B
*/