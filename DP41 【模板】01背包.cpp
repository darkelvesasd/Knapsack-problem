#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>>dp(m+1, vector<int>(1+n));
    vector<vector<int>>dp1(m + 1, vector<int>(1 + n));
    vector<int>v(m);
    vector<int>w(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i-1] >= 0)
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j - v[i-1]] + w[i-1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp1[0][i] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp1[i][j] = dp1[i - 1][j];
            if (j-v[i-1]>=0&& dp1[i - 1][j - v[i-1]] != -1)
            {
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }
    cout << dp[m][n]<<endl<< (dp1[m][n] == -1 ? 0 : dp[m][n]) << endl;
    return 0;
}
