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
    vector<int> v(n);
    for(int i = 0; i < n; i++) 
        cin >> v[i];
    
    
    if(n == 2) {
        cout << max(v[0], v[1]) << endl;
        return;  
    }
    sort(v.begin(), v.end());
    cout << v[(int)n/2] << endl;
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