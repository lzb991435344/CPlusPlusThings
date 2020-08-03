#include <iostream>
using namespace std;

//ok
/**
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heapInsert(int arr[], int index) {


	while (arr[index] > arr[(index - 1) / 2]) {
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

void heapify(int arr[], int index, int heapsize) {

	int left = 2 * index + 1;
	while (left < heapsize) {
		//寻找左右孩子中较大值的下标
		//右孩子不越界
		int largest = ((left + 1 < heapsize) && arr[left + 1] > arr[left]) ? left + 1 : left;

		//比较三者   index ，left + 1, left 之间的最大值的下标
		largest = arr[largest] > arr[index] ? largest : index;

		if (largest == index) {
			break;
		}
		swap(arr, largest, index);//调换最大值和当前的值
		index = largest;//当前值赋值为最大的索引

		left = 2 * index + 1;//左孩子继续往下找
	}
}

void heapSort(int arr[], int len) {
	//int len = sizeof(arr) / sizeof(arr[0]);
	//if (arr == NULL || len < 2) {
	//	return ;
	//}

	for (int i = 0; i < len; i++) {
		heapInsert(arr, i);
	}

	int heapsize = len;
	swap(arr, 0, --heapsize);

	while (heapsize > 0) {
		heapify(arr, 0, heapsize);
		swap(arr, 0, --heapsize);
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