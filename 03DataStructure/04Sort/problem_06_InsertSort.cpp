#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {

	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}


void insertSort(int arr[], int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; ++j ) {
			swap(arr, j , j + 1);
		}
	}
}

/*
int main() {


	int arr[5] = { 1,6,3,4,8 };
	int N = 5;

	insertSort(arr, N);
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << endl;
	}

	getchar();
	system("pause");
	return 0;
}*/