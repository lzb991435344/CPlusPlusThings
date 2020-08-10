// join 注意点

/**
 * 一旦线程开始，我们要想等待线程完成，需要在该对象上调用join()
 * 双重join将导致程序终止
 * 在join之前我们应该检查显示是否可以被join,通过使用joinable()
*/
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void run(int count) {
	while (count-- > 0) {
		cout << count << endl;
	}
	std::this_thread::sleep_for(chrono::seconds(3));
}
/**
int main() {
	thread t1(run, 10);
	cout << "main()" << endl;
	t1.join();

	if (t1.joinable()) {
		t1.join();
	}
	cout << "main() after" << endl;
	return 0;
}*/
//每次运行结果不一样，决定哪一个线程开始是调度器决定的
/*
9main()

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