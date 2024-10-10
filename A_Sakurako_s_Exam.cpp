// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int a,b;
   cin>>a>>b;
    if (a == 0) {
        if (b % 2 == 0)
            cout<< "YES"<<endl;
        else
            cout<< "NO"<<endl;
    } else {
        if ((2 * b - a) % 2 == 0)
            cout<< "YES"<<endl;
        else
            cout<< "NO"<<endl;
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