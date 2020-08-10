#include <thread>
#include <iostream>

using namespace std;

// 3.functor (Funciton Object)
//像函数的类
class Base {
public:
	void operator()(int x) {
		while (x-- > 0) {
			cout << x << endl;
		}
	}
};
/**
int main() {
	thread t(Base(), 10);
	t.join();
	return 0;
}*/
/**
9
8
7
6
5
4
3
2
1
0
*/