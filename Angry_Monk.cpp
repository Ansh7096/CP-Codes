// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n,k;
   cin>>n>>k;
   vector<int> v(k);
   int ans=0;

   for (int i=0;i<k;i++)cin>>v[i];
   sort(v.begin(),v.end());
   for(int i=0;i<k-1;i++)
   {
      ans+=v[i];
            ans+=v[i]-1;

   }

    cout<<ans<<endl;

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