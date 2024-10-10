// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n, s, m;
    cin >> n >> s >> m;
    int nn = n;
    vector<pair<int, int>> vp;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    int c = 0;
    int z = 0;
    for (auto it : vp)
    {
        if (it.first - z >= s)
        {
            cout << "YES" << endl;
            return;
        }
        z = it.second;
        c++;
        //cout<<c<<endl;
        if (c == nn)
        {
            //cout<<it.second<<endl;
            if (m - it.second >= s)
            {

                cout << "YES" << endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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