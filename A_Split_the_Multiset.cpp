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
        int ans=0;
        bool z=true;
        if(n==1){
        cout<<"0"<<endl;
        return;
        }
        else 
        { 
           while(n>1)
           {
            n=n-k+1;
            ans++;
           }
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
