class Solution {
public:
int lastStoneWeightII(vector<int>& stones) {
	int sum = 0;
	int n = stones.size();
	for (auto a : stones)
	{
		sum += a;
	}
	vector<vector<int>>v(n + 1, vector<int>(sum / 2+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <=sum/2 ; j++)
		{
			v[i][j] = v[i - 1][j];
			if (j >= stones[i - 1])
			{
				v[i][j] = max(v[i - 1][j], v[i - 1][j - stones[i - 1]]+stones[i-1]);
			}
		}
	}
	return sum - 2 *v[n][sum/2];
}
};
