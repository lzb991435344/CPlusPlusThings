#include <iostream>
#include <vector>
using namespace std;

class C {
public:
	C() {
		cout<< "I am C"<<endl;
	}
	vector<int> v;
	string s;
};
class D {
public:
	D() {
		cout << "I am D" << endl;
	}
	string s;
};

class X {
private:
	C c;
	D d;
};

/**
int main() {
	X x;
}*/

/**
I am C
I am D

*/