#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int sum = 0; //shared

mutex m;

void *countgold() {
	int i; //local to each thread
	for (i = 0; i < 10; i++) {
		m.lock();
		sum += 1;
		m.unlock();
	}
	return NULL;
}

/**
int main() {
	thread t1(countgold);
	thread t2(countgold);

	//Wait for both threads to finish
	t1.join();
	t2.join();

	cout << "sum = " << sum << endl;
	return 0;
}*/