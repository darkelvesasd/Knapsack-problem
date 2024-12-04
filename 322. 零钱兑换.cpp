class Solution {
public:
 int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	vector<int>v(amount+1);
	for (int j = 1; j <= amount; j++)
	{
		v[j] = 0x3f3f3f3f;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = coins[i-1]; j <= amount; j++)
		{
				v[j] = min(v[j],v[j - coins[i - 1]] + 1);
		}
	}
	return v[amount]==0x3f3f3f3f?-1:v[amount];
}
};
