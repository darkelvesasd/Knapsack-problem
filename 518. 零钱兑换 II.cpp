class Solution {
public:
int change(int amount, vector<int>& coins) {
	int n = coins.size();
	vector<double>v(amount + 1);
	v[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coins[i - 1]; j <= amount; j++)
		{
			v[j] += v[j - coins[i-1]];
		}
	}
	return v[amount];
}
};
