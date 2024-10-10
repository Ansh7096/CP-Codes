// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=26;
void sol()
{
   int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int>> pa(n + 1, vector<int>(N, 0));
        vector<vector<int>> pb(n + 1, vector<int>(N, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                pa[i + 1][j] = pa[i][j];
                pb[i + 1][j] = pb[i][j];
            }
            pa[i + 1][a[i] - 'a']++;
            pb[i + 1][b[i] - 'a']++;
        }

        
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--; 

            vector<int> za(N, 0);
            vector<int> zb(N, 0);

            for (int j = 0; j < N; j++) {
                za[j] = pa[r + 1][j] - pa[l][j];
                zb[j] = pb[r + 1][j] - pb[l][j];
            }

            int ans = 0;
            for (int j = 0; j < N; j++) 
                ans += abs(zb[j] - za[j]);
            
                ans=ans/2;
            cout << ans << endl;
        }
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