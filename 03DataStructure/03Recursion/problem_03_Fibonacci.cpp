#include <iostream>

using namespace std;

//ok

//O(2^N)
int f(int n) {
	if ( n < 0) {
		return -1;
	}
	if ( n == 1 || n == 2) {
		return 1;
	}
	return f(n - 1) + f(n - 2);
}

//o(N)
int f1(int n) {
	if (n < 0) {
		return -1;
	}
	if (n == 1 || n == 2) {
		return 1;
	}

	int res = 1;
	int pre = 1;
	int tmp = 0;
	for (int i = 3; i < n; i++) {
		tmp = res;//缓存变量res的值
		res = pre + res;//更新res的值
		pre = tmp;//重设pre变量
	}	
	return res;
}

//优化：矩阵乘法
int f2(int n) {

	return 1;
}
/**
int main() {

	getchar();
	system("pause");
	return 0;
}*/