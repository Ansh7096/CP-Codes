// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n;
        int m;
        cin >> n >> m;
        vector<int> v(n);

        for (int i = 0; i < n; ++i) 
            cin >> v[i];
        sort(v.begin(), v.end());

        int ans = 0;
        int z = 0;
        int z1 = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            z += v[r];
            z1 += v[r];

            while (v[r] - v[l] > 1 || z > m) {
                z -= v[l];
                z1 -= v[l];
                l++;
            }

            ans = max(ans, z1);
        }

        cout << ans << endl;
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