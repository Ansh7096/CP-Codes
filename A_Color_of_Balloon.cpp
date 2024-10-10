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
   cin>>n;
   map<string,int> m;
   for(int i=0;i<n;i++)
   {
    string s;
    cin>>s;
    m[s]++;
   }
   double z=n/2;
   for(auto i:m)
   {
     if((double)i.second>z)
     {
        cout<<i.first<<endl;
        return ;
     }
   }
   cout<<"uh-oh"<<endl;
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