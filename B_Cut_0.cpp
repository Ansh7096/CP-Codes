// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    string s;
    cin >> s;

    double number = stod(s);
   
    ostringstream oss;
    oss << fixed << setprecision(10) << number;
    string ans = oss.str();
    
    auto z = ans.find_last_not_of('0');
    if (ans[z] == '.') 
        z--;  
    
    ans.erase(z + 1);

    cout << ans << endl;
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