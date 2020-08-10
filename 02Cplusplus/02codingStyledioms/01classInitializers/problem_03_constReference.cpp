#include <iostream>

class Animal {
public:
	Animal(int age, std::string name) :age_(age), name_(name) {
		//puts();
		std::cout << "age is:"<<age<< " "<<"Animal(int age) is called" << std::endl;
	}
private:
	int &age_;
	const std::string name_;
};
/**
int main() {
	Animal animal(10, "hh");
	return 0;
}*/
/**
age is:10 Animal(int age) is called

*/