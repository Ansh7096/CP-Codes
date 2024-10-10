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
   string s,ss;
   cin>>s;
   for(int i=0;i<n;i++)
   {
    if(i==0)ss.push_back(s[i]);
    else{
        if(s[i]==s[i-1]&&s[i]=='0')continue;
        else
        ss.push_back(s[i]);
    }
   }
    int c1=0,c2=0;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='1')c1++;
        else c2++;
    }
   if(c1>c2)cout<<"Yes"<<endl;
   else 
   cout<<"No"<<endl;
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