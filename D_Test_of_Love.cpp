// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int z = m - 1, w = 0, z2 = 0;
    for (char c : s) {
        if (c == 'L') z = m;
        else if (c == 'W') {
            if (z <= 0) w++;
        } else {
            if (z <= 0) z2++;
        }
        z--;
    }

     if(w > k) z2++;
      if(z2==0)cout<<"YES"<<endl;
      else 
      cout<<"NO"<<endl;
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