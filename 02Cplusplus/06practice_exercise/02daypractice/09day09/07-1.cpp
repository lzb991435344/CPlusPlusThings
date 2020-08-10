#include<iostream>
using namespace std;


class A {
	int a;
public:
	A(int i = 0) :a(i) {}
	~A() { cout << "in A destructor..." << endl; }
};


class B {
	A obj[3];
	double *pb[10];
public:
	B(int k) {
		cout << "int B constructor..." << endl;
		for (int i = 0; i < 10; i++) {
			pb[i] = new double[20000000];
			if (pb[i] == 0)
				throw i;
			else
				cout << "Allocated 20000000 doubles in pb[" << i << "]" << endl;
		}
	}
};


/**
int main() {
	try {
		B b(2);
	}
	catch (int e) {
		cout << "catch an exception when allocated pb[" << e << "]" << endl;
	}
	system("pause");
}*/

/**
int B constructor...
Allocated 20000000 doubles in pb[0]
Allocated 20000000 doubles in pb[1]
Allocated 20000000 doubles in pb[2]
Allocated 20000000 doubles in pb[3]
Allocated 20000000 doubles in pb[4]
Allocated 20000000 doubles in pb[5]
Allocated 20000000 doubles in pb[6]
Allocated 20000000 doubles in pb[7]
Allocated 20000000 doubles in pb[8]
Allocated 20000000 doubles in pb[9]
in A destructor...
in A destructor...
in A destructor...

*/