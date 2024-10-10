#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int l, r;
        cin >> l >> r;
        int minOps = 0;
        while (r > 0) {
            minOps++;
            r /= 3;
        }
        cout << minOps + (r - l) << endl;
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