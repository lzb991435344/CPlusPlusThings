#include <thread>
#include <iostream>

using namespace std;

// 4.static member function
class Base {
public:
	static void fun(int x) {
		while (x-- > 0) {
			cout << x << " ";
		}
	}
};
/**
int main() {
	thread t(&Base::fun, 10);
	t.join();
	return 0;
}*/
/*
9 8 7 6 5 4 3 2 1 0
*/