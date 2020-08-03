#include <iostream>

using namespace std;


//ok
void swap1(int arr[], int i , int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void buddleSort(int arr[], int N) {

	for (int end = N; end > 0; end--) {
		for (int i = 0; i < end; i ++) {
			
			if (arr[i] > arr[i + 1]) {
				swap1(arr, i, i + 1);
			}
		}
	}
}

/**
int main() {
	

	int arr[5] = {3,5,2,4,1};
	buddleSort(arr, 5);
	for (int i = 0; i < 5; i++ ) {
		cout<< arr[i]<<endl;
	}
	getchar();
	system("pause");
	return 0;
}*/