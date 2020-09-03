
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;
/**
using ull = unsigned long long;
ull OddSum = 0;  //奇数 
ull EvenSum = 0; //偶数

void findEven(ull start, ull end) {
	for (ull i = start; i <= end; ++i)
		if ((i & 1) == 0)
			EvenSum += i;
}

void findOdd(ull start, ull end) {
	for (ull i = start; i <= end; ++i)
		if ((i & 1) == 1)
			OddSum += i;
}*/
/**
int main() {

	ull start = 0, end = 1900000000;

	//high_resolution_clock::now() 返回的时间以秒为单位
	auto startTime = high_resolution_clock::now();
	findOdd(start, end);
	findEven(start, end);
	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum: " << EvenSum << endl;
	cout << "Sec: " << duration.count() / 1000000 << endl; //1s = 10^6 us
	return 0;
}*/
/**
OddSum : 902500000000000000
EvenSum: 902500000950000000
Sec: 11
*/