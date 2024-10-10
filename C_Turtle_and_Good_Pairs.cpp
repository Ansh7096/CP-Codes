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
    string s;
    cin >> s; 
    unordered_map<char,int> um;
    for (char i : s) 
        um[i]++;
    string ans = "";
    
    while (ans.size() < n) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (um[c] > 0) {
                um[c]--;
                ans.push_back(c);
            }
        }
    }
    
    cout << ans << endl;
    
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