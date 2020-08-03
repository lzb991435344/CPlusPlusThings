

#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
/***
题目描述
吃货LP参加了珠海美食节，每见一家摊位都会大吃一顿，但是如果不加收敛，接下来的日子就只能吃土了，所以，他决定只向前，不回头，花最少的钱，在美食节上吃出一条血路。在美食节的矩形地图中，LP站在左上角的入口，请帮助Ta到达右下角的出口。
输入描述 :
第一行包含一个正整数T(T <= 10)，表示有T组测试数据。
每组数据第一行包含一个正整数n(3 <= n <= 20）。
	给定一个n*n矩阵图，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径上所有的数字累加起来就是花费和，返回所有路径中最小的花费和。
	无摊位时花费为0，不会有负花费。
	输出描述 :
对于每一组数据，有一行输出，返回最小花费，最后输出无换行。
示例1
输入
1
5
25 81 51 98 43
19 10 36 81 91
95 38 7 84 40
87 27 72 9 30
33 81 68 21 71

输出
270
*/
using namespace std;
const int N = 24;
int a[N][N];
int dp[N][N];
const int INF = 0x3f3f3f3f;


int min(int a, int b) {
	return (a) < (b) ? (a) : (b);
}

//暴力递归
int MinPath(int arr[][24], int i , int j, int n) {
	if (i == n && j == n) {
		return arr[i][j];
	}

	if (i == n) {
		return arr[i][j] + MinPath(arr, i, j + 1, n);
	}

	if (j == n) {
		return arr[i][j] + MinPath(arr, i + 1, j, n);
	}

	int rightSum = MinPath(arr, i, j + 1, n);
	int downSum = MinPath(arr, i + 1, j , n);

	return min(rightSum, downSum) + arr[i][j];
}



//dp
int MinPath2(int arr[][24], int k) {
	dp[1][1] = a[1][1];
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + a[i][j]);
		}
	}
	return dp[k][k];
}

/**
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				cin >> a[i][j];
			}
		}
		memset(dp, INF, sizeof(dp));
		int res = MinPath2(a, k);
		cout << res <<endl;
	}

	getchar();
	system("pause");
	return 0;
}*/
