class Solution {
public:
int findTargetSumWays(vector<int>& nums, int target) {
	int sum = 0;
	for (auto a : nums)
	{
		sum += a;
	}
	int n = nums.size();
	if ((target + sum) % 2 == 1|| (target + sum) / 2<0)
	{
		return 0;
	}
	vector<vector<int>>v(n + 1, vector<int>((sum + target) / 2+1));
	v[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= (target + sum) / 2; j++)
		{
			v[i][j] = v[i - 1][j];
			if (j >= nums[i - 1])
			{
				v[i][j] += v[i - 1][j - nums[i - 1]];
			}
		}
	}
	return v[n][(sum+target)/2];
}
};
