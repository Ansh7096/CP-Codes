// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n, x;
        cin >> n >> x;

       int ans = 0;
        for (int a = 1; a <= x; a++) {
            int mb = min(x - a, n / a);
            for (int b = 1; b <= mb; b++) {
                int mc = min(x - a - b, (n - a * b) / (a + b));
                ans += max(0LL, mc);
            }
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