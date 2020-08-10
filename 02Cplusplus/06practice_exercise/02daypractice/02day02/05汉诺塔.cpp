#include<iostream>
using namespace std;
void move(char A, char B);
void hanoi(int n, char A, char B, char C);



void move(char A, char B)
{
	cout << A << "->" << B << endl;
}

void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		move(A, C);
	}
	else
	{
		hanoi(n - 1, A, C, B);
		move(A, C);
		hanoi(n - 1, B, A, C);
	}
}
/**
int main(int argc, char const *argv[])
{
	cout << "move";
	int disks;
	cin >> disks;
	hanoi(disks, 'A', 'B', 'C');
	system("pause");
	return 0;
}*/

/**
move2
A->B
A->C
B->C

*/