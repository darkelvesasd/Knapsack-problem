class Solution {
public:
    int numSquares(int n) {
	int a = sqrt(n);
	vector<int>v(n+1,0x3f3f3f3f);
	v[0] = 0;
	for (int i = 1; i <= a; i++)
	{
		for (int j = i*i; j <= n; j++)
		{
			v[j] = min(v[j], v[j-i*i] + 1);
		}
	}
	return v[n];
}
};
