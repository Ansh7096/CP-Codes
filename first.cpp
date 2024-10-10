// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int getSmallestSubarrayLength(int k,vector<int> amount)
{
set<int> s;
    int n = amount.size();
    s.insert(0);
    map<int, int> mp;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (auto it : s)
        {
            if (mp[it + amount[i] - k])
                mini = min(mini, i + 1 - mp[it + amount[i] - k]);
            s.insert(it + amount[i]);
            mp[it + amount[i]] = i + 1;
        }
    }
    return mini;
}
void sol()
{
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++)
   cin>>v[i];
   int k;
   cin>>k;
int ans=getSmallestSubarrayLength(k,v);

cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        sol();
    }
}