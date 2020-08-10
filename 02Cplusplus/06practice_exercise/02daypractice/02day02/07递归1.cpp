#include<iostream>
using namespace std;

int f(int n);
/**
int main(int argc, char const *argv[])
{
	cout << "input x:";
	int x;
	cin >> x;
	cout << f7(x) << endl;
	system("pause");
	return 0;
}*/

/**
---MAIN---
 i: 1 a: 0 b: -10 c: 0
---OTHER---
 i: 33 a: 4 b: 0 c: 15
---MAIN---
 i: 33 a: 0 b: -10 c: 8
---OTHER---
 i: 75 a: 6 b: 4 c: 15
---OTHER---
 i: 107 a: 8 b: 6 c: 15

*/

int f7(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * f(n - 1);
	}
}