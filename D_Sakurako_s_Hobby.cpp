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
    cin >> n;
    vector<int> p(n);
    vector<int> vc(n);
    vector<bool> vis(n, false);
    string s;
    
    for (int i = 0; i < n; i++) 
        cin >> p[i];
    cin >> s;
    for (int i = 0; i < n; i++) 
        vc[i] = s[i] - '0';


    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<int> c;
            int x = i;
            while (!vis[x]) {
                vis[x] = true;
                c.push_back(x);
                x = p[x]-1;
            }
            int z = 0;
            for (int ii : c) {
                if (vc[ii] == 0) 
                    z++;
                
            }
            for (int ii : c) 
                ans[ii] = z;
            
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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