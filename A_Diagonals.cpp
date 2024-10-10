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
        int ans = 0;

        if (k > 0) {
            ans++;
            k -= n;
            n--;
        }
        else 
        n--;
        

        while (k > 0) {
            k-=n;
            ans++;
            if (k > 0) {
                ans++;
                k -= n;
            n--;
            }
            else n--;
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