#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<queue>
#include<unordered_set>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	vector<int>v(a);
	vector<int>w(a);
	for (int i = 0; i < a; i++)
	{
		cin >> v[i] >> w[i];
	}
	vector<vector<int>>dp(a + 1, vector<int>(b + 1));
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i - 1])
			{
				dp[i][j] = max(dp[i][j], dp[i][j - v[i - 1]] + w[i-1]);
			}
		}
	}
	cout << dp[a][b] << endl;
	vector<vector<int>>dp1(a + 1, vector<int>(b + 1));
	for (int j = 1; j <= b; j++)
	{
		dp1[0][j] = -1;
	}
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			dp1[i][j] = dp1[i - 1][j];
			if (j >= v[i - 1] && dp1[i][j - v[i - 1]] != -1)
			{
				dp1[i][j] = max(dp1[i][j], dp1[i][j - v[i - 1]] + w[i - 1]);
			}
		}
	}
	cout << dp1[a][b];
}
