#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;


//生成1-N的全排列
 volatile int count = 0;
//ok
//01打印所有子串
void printAllSubString(string str, int index, string res) {
	
	if (index == str.length()) {
		
		for (int i = 0; i < res.length(); i++) {
			//cout << res.length() << endl;
			cout << res[i];
		}	
		cout << res.length();
		return;
	}
	
	printAllSubString(str, index + 1, res);//不含index位置的字符
	printAllSubString(str, index + 1, res + str[index]);//包含index位置的字符
}


void swap(char arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

char* strToChar(string str) {
	if (str.size() < 0) {
		return NULL;
	}

	int len = str.size() + 1;
	char arr[] = {0};
	for (int i = 0; i < len; ++i) {
		arr[i] = str[i];
	}
	arr[len - 1] = '\0';
	
	return arr;
}

void process1(char* arr, int i, int len) {
	if (arr == NULL) {
		return;
	}

	if (i == len) {
		for (int k = 0; k < len; ++k) {
			cout<< arr[k];
		}
	}

	for (int j = i; j < len; ++j) {
		swap(arr, i, j);
		process1(arr, i + 1, len);
		swap(arr, i, j);
	}
}
//02打印全排列
void printAllPermutationSequencestrin(string str){

	char * arr = strToChar(str);
	int len = strlen(arr);
	process1(arr, 0, len);
}


//打印
void permute(list<char> pre, list<char> str) {
	if (!str.empty()) {
		for (auto i = str.begin(); i != str.end(); ++i) {
			list<char> curPre(pre);
			list<char> tmpList(str.begin(), str.end());
			curPre.push_back(*i);
			tmpList.remove(*i);
			permute(curPre, tmpList);
		}
	}
	else {
		copy(pre.begin(), pre.end(), ostream_iterator<char>(cout, ""));
		cout << endl;
	}

}

void print(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		if (i < len - 1)
		{
			cout << ",";
		}
		else if (i == len - 1)
		{
			cout << endl;
		}
	}
}

void swap2(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void recall(int* arr, int len, int index)
{
	if (index <= 0)
	{
		print(arr, len);
		//count++;
		return;
	}
	for (int i = index; i >= 0; i--)
	{
		swap2(&arr[index], &arr[i]);
		recall(arr, len, index - 1);
		swap2(&arr[index], &arr[i]);
	}
}


/**
int main() {
	//string str = "abc";
	//printAllSubString(str,0, "");
	//printAllPermutationSequencestrin(str);

	//char *alphabet = const_cast<char *>("abc");
	//list<char> str(alphabet, &alphabet[3]);
	//permute(list<char>(), str);

	int N;
	cin >> N;
	int(*arr) = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	recall(arr, N, N - 1);
	//cout << "全排列个数为：" << count << endl;

	getchar();
	system("pause");
	return 0;
}*/