/* Compile code without optimization option */
#include <stdio.h> 


/**
int main(void)
{
	const int local = 10;
	int *ptr = (int*)&local;

	printf("Initial value of local : %d \n", local);
	*ptr = 100;

	printf("Modified value of local: %d \n", local);


	getchar();
	return 0;
}*/
/**
Initial value of local : 10
Modified value of local: 10
*/