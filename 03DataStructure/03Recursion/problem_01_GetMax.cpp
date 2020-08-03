#include <iostream>
#include <algorithm>
using namespace std;


int tmax(int a,int b) {
	return a < b ? b : a;
}

int getMax(int arr[], int l,int r) {

	if (l == r) {
		return arr[l];
	}

	int max = INT_MIN;
	int mid = l + ((r - l) >> 1);
	int lmax = getMax(arr, l , mid);
	int rmax = getMax(arr, mid + 1, r);

	return tmax(lmax, rmax);
}

/**
int main() {

	int arr[6] = { 1,6,2,3,9,8 };
	cout<< getMax(arr, 0, 5)<<endl;

	getchar();
	system("pause");
	return 0;
}*/