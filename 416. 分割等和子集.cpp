class Solution {
public:
bool canPartition(vector<int>& nums) {
	int sum = 0;
	for (auto a : nums)
	{
		sum += a;
	}
	if (sum % 2 == 1)
	{
		return false;
	}
	int n = nums.size();
	vector<vector<bool>>v(n + 1, vector<bool>(sum / 2+1));
	for (int j = 1; j <= n; j++)
	{
		v[j] [0] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum / 2; j++)
		{
			v[i][j] = v[i - 1][j] || j - nums[i - 1] >= 0 && v[i - 1][j - nums[i - 1]];
		}
	}
	return v[n][sum / 2];
}
};
