// 多个背包.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	int n, t, m;
	while (cin >> n >> t >> m)
	{
		vector<int>p(n);
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		reverse(p.begin(), p.end());
		vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(t + 1, 0)));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 0; k <= t; ++k)
				{
					if (p[i] <= k)
					{
						if (i - 1 >= 0)
							dp[i][j][k] = max(dp[i - 1][j][k - p[i]] + 1, dp[i][j][k]);
						else dp[i][j][k] = max(dp[i][j][k], 1);
						if (i - 1 >= 0)
							dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k]);
						if (j - 1 >= 0)
							dp[i][j][k] = max(dp[i][j - 1][t], dp[i][j][k]);
					}
					else 
					{
						if (i - 1 >= 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
						if (j - 1 >= 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][t]);
					}
				}
		cout << dp[n - 1][m - 1][t];
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
