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
    cin >> n;

    vector<int> x(n);
    vector<int> p(n);

    for (int i = 0; i < n; i++) 
        cin >> x[i];
    
    for (int i = 0; i < n; i++) 
        cin >> p[i];
    
    vector<long long> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        ps[i] = ps[i - 1] + p[i - 1];

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        
        int l1 = lower_bound(x.begin(), x.end(), l) - x.begin();
        int r1 = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;

        if (l1 > r1) 
            cout << 0 << endl;
        else 
            cout << ps[r1 + 1] - ps[l1] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        sol();
    }
}
