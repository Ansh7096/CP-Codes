// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int a, b, c;
        cin >> a >> b >> c;
        for (int i = 1; i <= 5; i++) {
            if(a<=b && a<=c)a++;
            else if(b<=a&&b<=c)b++;
            else c++;
           
        }
        
        cout << a*b*c << endl;
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