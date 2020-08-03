#include <iostream>
using namespace std;

//void merge1(int arr[], int l, int mid, int r);
//int help[7] = { 0 };
void merge1(int arr[], int help[], int l, int mid, int r) {
	int p1 = l;
	int p2 = mid + 1;
	int i = 0;
	//int len1 = sizeof(arr) / sizeof(arr[0]);
	//int help[7] = {0};

	while (p1 <= mid && p2 <= r) {
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}

	while (p1 <= mid) {
		help[i++] = arr[p1++];
	}

	while (p2 <= r) {
		help[i++] = arr[p2++];
	}

	int len = (sizeof(help) / sizeof(help[0]));

	for (i = 0; i < len; i++) {
		arr[i] = help[i];
	}
}

void mergeSort(int arr[], int help[], int l, int r) {
	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	mergeSort(arr, help, l, mid);
	mergeSort(arr, help, mid + 1, r);
	//mergeSort(arr, help, l, r);
	merge1(arr, help, l, mid, r);
}

/**
int main() {



	getchar();
	system("pause");
	return 0;
}*/