
/**
#include<iostream>
#include"apple2.cpp"
using namespace std;
const int Apple::apple_number = 10;
int Apple::ap = 666;
Apple::Apple(int i)
{

}
int Apple::add(int num) {
	take(num);
	return apple_number;
}
int Apple::add(int num) const {
	take(num);
	return apple_number;
}
void Apple::take(int num) const
{
	cout << "take func " << num << endl;
}
int Apple::getCount() const
{
	take(1);
	//    add(); //error
	return apple_number;
}
/**
int main() {
	Apple a(2);
	cout << a.getCount() << endl;
	cout << a.ap << endl;
	a.add(10);
	const Apple b(3);
	b.add(100);

	getchar();
	return 0;
}*/
/**
take func 1
10
666
take func 10
take func 100

*/