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
        string s;
        cin >> n >> s;

        if (s[0] != s[n-1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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