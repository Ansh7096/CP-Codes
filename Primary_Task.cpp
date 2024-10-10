// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string s;
    cin >> s;

    if (s.size() < 3 || s[0] != '1' || s[1] != '0') {
        cout << "NO" << endl;
        return;
    }

  
    string ss = s.substr(2);

   
    if (ss.empty() || ss[0] == '0' || stoi(ss) < 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}