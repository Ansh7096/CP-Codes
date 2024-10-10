// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e9;
void sol()
{
   int n, k; 
    cin >> n >> k;

    vector<vector<int>> cost(n + 1, vector<int>(k + 1, N));
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, N));

  
    for (int i = 1; i <= n; i++) {
        int a, b; 
        cin >> a >> b;
        cost[i][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int r = 0; r <= p; r++) {
                int c = p - r;
                if (r <= a && c <= b) {
                    cost[i][p] = min(cost[i][p], r * b + c * a - r * c);
                }
            }
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = j; t <= k; t++) {
                dp[i + 1][t] = min(dp[i + 1][t], dp[i][j] + cost[i + 1][t - j]);
            }
        }
    }

    if (dp[n][k] == N) 
        dp[n][k] = -1;
    

    cout << dp[n][k] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //t = 1;
    cin>>t;
    while (t--)
    {
        sol();
    }
}