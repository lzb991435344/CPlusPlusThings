#include <stdio.h> 
#include <iostream>
#include <assert.h> 

//断言主要用于检查逻辑上不可能的情况。
//于检查代码在开始运行之前所期望的状态，或者在运行完成后检查状态。
//与正常的错误处理不同，断言通常在运行时被禁用。
/**
int main()
{
	int x = 7;

	 // Some big code in between and let's say x
	 //        is accidentally changed to 9  
	x = 9;

	// Programmer assumes x to be 7 in rest of the code 
	assert(x == 7);
	std::cout << x << std::endl;
	// Rest of the code 

	system("pause");
	return 0;
}*/