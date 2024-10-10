// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod=1000000007;
void sol()
{
   string s;
   cin>>s;
   int n=s.size();
   int ans=1;
   vector<int> v(n+1,0);
   vector<int> dp(n*2+2,0);
   for(int i=0;i<n;i++)
   {
    v[i+1]=v[i];
    if(s[i]=='1')
        v[i+1]+=1;
    else 
        v[i+1]+=-1;
   }
// for(int i=0;i<n;i++) cout<<v[i]<<" ";
   for(int i=1;i<=n;i++)
   {
      dp[n+v[i-1]]=(dp[n+v[i-1]]+i)%mod;
      ans=(ans+dp[n+v[i]]*(n-i+1))%mod;
      //cout<<ans<<endl;
   }
   cout<<ans-1<<endl;
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