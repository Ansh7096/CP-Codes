// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n, k;
        cin >> n >> k;
        vector<string> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int l = n / k;
    vector<string> ans(l, string(l, ' '));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            ans[i][j] = s[i * k][j * k];
        }
    }

    for (const auto& i: ans) 
        cout << i << endl;
    
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