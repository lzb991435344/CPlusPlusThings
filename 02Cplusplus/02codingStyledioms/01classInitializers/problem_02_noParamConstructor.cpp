#include <iostream>
class Animal {
public:
	Animal(int age) {
		std::cout << "age is"<< age << std::endl;
		std::cout << "Animal(int age) is called" << std::endl;
	}

	Animal(const Animal & animal) {
		std::cout << "Animal (const Animal &) is called" << std::endl;
	}

	Animal &operator=(const Animal & amimal) {
		std::cout << "Animal & operator=(const Animal &) is called" << std::endl;
		return *this;
	}

	~Animal() {
		std::cout << "~Animal() is called" << std::endl;
	}

};

class Dog : Animal {
public:
	Dog(int age) : Animal(age) {
		std::cout << "Dog(int age) is called" << std::endl;
	}

	~Dog() {
		std::cout << "~Dog() is called" << std::endl;
	}
};

/**
int main() {
	Animal animal(10);
	std::cout << std::endl;
	Dog d(100);
	std::cout << std::endl;
	return 0;
}*/
/**
age is10
Animal(int age) is called

age is100
Animal(int age) is called
Dog(int age) is called

~Dog() is called
~Animal() is called
~Animal() is called

*/