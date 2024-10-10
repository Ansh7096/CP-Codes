// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n, m, x = 0, y;
        char c;
        
        cin >> n >> m;
       
        while (n--) {
            cin >> y;
            x = max(x, y);
        }
        
       
        while (m--) {
            cin >> c >> n >> y;
            
            
            if (n <= x && x <= y) {
                if (c > 44) { 
                    x--;
                } else {
                    x++;
                }
            }
            
            cout << x << ' ';
        }
        
        cout << endl;
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