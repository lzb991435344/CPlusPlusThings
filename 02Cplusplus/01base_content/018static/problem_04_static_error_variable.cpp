// variables inside a class 

#include<iostream> 
using namespace std;

class Apple
{
public:
	//内存中只有一份
	static int i;

	Apple()
	{
		// Do nothing 
	};
};
int Apple::i = 0;
/**
int main()
{
	Apple obj1;
	Apple obj2;
	obj1.i = 2;
	obj2.i = 3;

	// prints value of i 
	cout << obj1.i << " " << obj2.i;

	return 0;
}*/
/*
3 3
*/