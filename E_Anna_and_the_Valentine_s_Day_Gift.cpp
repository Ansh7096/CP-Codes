// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), z;
    for (int i = 0; i < n; i++) cin >> v[i];
    
    for (auto i : v)
    {
        int zz = 0, d = 0;
        while (i % 10 == 0) zz++, i /= 10;
        while (i) d++, i /= 10;
        m -= d;
        z.push_back(zz);
    }
    
    sort(z.begin(), z.end(), greater<int>());  

    for (int i = 1; i < z.size(); i += 2) m -= z[i];  
    
    if (m < 0)
        cout << "Sasha" << endl;
    else
        cout << "Anna" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
}
