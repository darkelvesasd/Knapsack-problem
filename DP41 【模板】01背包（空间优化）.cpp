#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int>dp( 1+n);
    vector<int>dp1(1 + n);
    vector<int>v(m);
    vector<int>w(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >=0 ; j--)
        {
            dp[j] = dp[j];
            if (j - v[i-1] >= 0)
            {
                dp[j] = max(dp[j],dp[j - v[i-1]] + w[i-1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp1[i] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >=0 ; j--)
        {
            dp1[j] = dp1[j];
            if (j-v[i-1]>=0&& dp1[j - v[i-1]] != -1)
            {
                dp1[j] = max(dp1[j], dp1[j - v[i - 1]] + w[i - 1]);
            }
        }
    }
    cout << dp[n]<<endl<< (dp1[n] == -1 ? 0 : dp1[n]) << endl;
    return 0;
}
