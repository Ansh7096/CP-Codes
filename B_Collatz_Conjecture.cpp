// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int x, y, k;
    cin >> x >> y >> k;
    int z = y - x % y;
    
    if (k <= z) {
        x += k;
        if (k == z) {
            while (x % y == 0) x /= y;
        }
        cout << x << endl;
        return;
    }

    k -= z;
    x += z;
    while (x % y == 0) x /= y;
    
    while (x > 1 && k >= (z = y - x % y)) {
        k -= z;
        x += z;
        while (x % y == 0) x /= y;
    }
    
    cout << (x == 1 ? k % (y - 1) + 1 : x + k) << endl;
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