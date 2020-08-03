#include <iostream>

using namespace std;


//ok
/**
void swap(int arr[], int i , int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}*/

void selectSort(int arr[], int m) {

	for (int i = 0; i < m; ++i) {
		int index = i;//index是可变的，每次使用时都重新赋值

		//遍历从1开始，找到最小值的位置
		for (int j = i + 1; j < m; ++j) {
			index = arr[j] < arr[index] ? j : index;
		}
		//swap(arr, i, index);
	}
}

/***
int main() {

	int arr[5] = { 1,6,3,4,8 };
	int N = 5;

	selectSort(arr, N);
	for (int i = 0; i < N; ++i) {
		cout<<arr[i] <<endl;
	}


	getchar();
	system("pause");
	return 0;
}*/