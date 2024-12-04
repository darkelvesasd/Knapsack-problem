class Solution {
public:
int findMaxForm(vector<string>& strs, int m, int n) {
	int len = strs.size();
	vector<vector<int>>dp(len, vector<int>(2));
	for (int i = 0; i < len; i++)
	{
		for (auto b : strs[i])
		{
			if (b == '1')
			{
				dp[i][1]++;
			}
			else
			{
				dp[i][0]++;
			}
		}
	}
	vector<vector<int>>v(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= len; i++)
	{
		for (int j = m; j >= dp[i - 1][0]; j--)
		{
			for (int k = n; k >= dp[i - 1][1]; k--)
			{
				v[j][k] = max(v[j][k], v[j - dp[i - 1][0]][k - dp[i - 1][1]] + 1);
			}
		}
	}
	return v[m][n];
}
};
