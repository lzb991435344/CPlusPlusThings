#include<iostream>
using namespace std;
//相同的内存地址
union myun
{
	//联合体占用内存大小是根据其最大元素所需要的内存所决定的
	struct { int x; int y; int z; }u;
	int k;
}a;
/**
int main()
{
	a.u.x = 4;
	a.u.y = 5;
	a.u.z = 6;
	a.k = 0; //覆盖掉第一个int空间值
	printf("%d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k);
	cout<< sizeof(a)<<endl; //12
	system("pause");
	return 0;
}*/
/**
0 5 6 0 12
*/