// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int a, b, x;
        cin >> a >> b >> x;
        
        if (a * b <= x * x) 
            cout << "0" << endl;
         else if (x * x >= a || x * x >= b) 
            cout << "1" << endl;
        else 
            cout << "2" << endl;
        
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