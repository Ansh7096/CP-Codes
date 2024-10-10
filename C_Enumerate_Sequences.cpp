// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void check(int idx, int n, int k, vector<int>& v, vector<int>& c, vector<vector<int>>& ans)
{
    if(idx==n)
    {
        int s=0;
        for(int i=0;i<c.size();i++)s+=c[i];
        if(s%k==0)
        ans.push_back(c);
        return;
    }
    for(int i=1;i<=v[idx];i++)
    {
        c[idx]=i;
        check(idx+1,n,k,v,c,ans);
    }
}
void sol()
{
   int n,k;
   cin>>n>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++)
   {
    cin>>v[i];
   }
   vector<int> c(n);
   vector<vector<int>> ans;

   check(0,n,k,v,c,ans);

   for(auto i:ans)
   {
    for(auto ii:i)
    cout<<ii<<" ";
    cout<<endl;
   }
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