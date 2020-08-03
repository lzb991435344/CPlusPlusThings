#include <iostream>
using namespace std;

/**
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int* partionArray(int *arr, int l, int r) {
	int less = l - 1;
	//int less = l;
	int more = r;
	while (l < more) {
		if (arr[l] < arr[r]) {
			swap(arr, ++less, l++);
		}
		else if (arr[l] > arr[r]) {
			swap(arr, --more, l);
		}
		else {
			l++;
		}
	}
	swap(arr, more, r);
	int p[2] = { less + 1 , more };
	//arr[0] = { less + 1 };
	//arr[1] = more;
	return p;
}

void quickSort(int arr[], int l, int r) {
	if (l <= r) {

		int* p = partionArray(arr, l, r);

		quickSort(arr, l, p[0] - 1);
		quickSort(arr, p[1] + 1, r);
	}
}

int main() {

	int arr[7] = { 1, 5, 3, 7, 2, 8, 4 };
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << endl;
	}
	getchar();
	system("pause");
	return 0;
}*/