#include <iostream>

using namespace std;

class A {
public:
	A(int a) : _a(a), _p(nullptr) {     // 初始化列表

	}

public:
	int _a;
	int *_p;
};
/**
int main() {
	A aa(10);
	int a = 10;
	aa._p = &a;
	std::cout << aa._a << *(aa._p) << endl;
	return 0;
}*/
/**
10 10
*/