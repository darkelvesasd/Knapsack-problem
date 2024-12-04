class Solution {
public:
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
	int a = group.size();
	vector<vector<int>>v(n+1, vector<int>(1+minProfit));
	for (int j = 0; j <= n; j++)
	{
		v[j][0] = 1;
	}
	for (int i = 1; i <= a; i++)//组
	{
		for (int j = n; j >= group[i - 1]; j--)//人
		{
			for (int k = minProfit; k >=0; k--)//价格
			{
				v[j][k] +=v[j - group[i-1]][max(0,k - profit[i-1])];
                v[j][k]%=1000000007;
			}
		}
	}
	return v[n][minProfit];
}
};
