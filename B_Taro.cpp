// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n, m;
    cin >> n >> m;
    
    vector<bool> v(n + 1, false);  
    
    for (int i = 0; i < m; i++) {
        int a;  
        char b;
        cin >> a >> b;
        
        if (b == 'M' && !v[a]) {
            cout << "Yes" << endl;
            v[a] = true;  
        } else {
            cout << "No" << endl;
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t= 1;
    //cin>>t;
    while (t--)
    {
        sol();
    }
}