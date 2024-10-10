// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   char sab,sac,sbc;
   cin>>sab>>sac>>sbc;
   int a=0,b=0,c=0;
   if(sab=='>')a++;
   else b++;
if(sac=='>')a++;
   else c++;

   if(sbc=='>')b++;
   else c++;

   if(a==1)
   cout<<"A"<<endl;
   else if(b==1)
   cout<<"B"<<endl;
   else 
   cout<<"C"<<endl;

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