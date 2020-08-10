#include<iostream>
#include<cstring>

//#define NO _CRT_SECURE_NO_WARNINGS
using namespace std;
class Person {
public:
	typedef enum {
		BOY = 0,
		GIRL
	}SexType;
	Person(char *n, int a, SexType s) {
		name = new char[strlen(n) + 1];
		strcpy(name, (char*)n);
		age = a;
		sex = s;
	}
	int get_age() const {

		return this->age;
	}
	Person& add_age(int a) {
		age += a;
		return *this;
	}
	~Person() {
		delete[] name;
	}
private:
	char * name;
	int age;
	SexType sex;
};

/**
int main() {
	char str[] = "zhangsan";
	Person p(str, 20, Person::BOY);
	cout << p.get_age() << endl;//20

	return 0;
}*/
