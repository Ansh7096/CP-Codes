// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int X, Y, K;
    cin >> X >> Y >> K;
    int z = abs(X - Y);

    if (z <= K) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    
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