// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int mx(const vector<int> &counts) {
    return *max_element(counts.begin(), counts.end());
}

void sol() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> ec(26, 0), oc(26, 0); 
    int mxx = 1e9;
    
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                ec[s[i] - 'a']++;
            else
                oc[s[i] - 'a']++;
        }
        cout << n / 2 - mx(ec) + n / 2 - mx(oc) << endl;
    } else {
        if (n == 1) {
            cout << 1 << endl;
            return;
        }

        vector<int> ps1(26, 0), ps2(26, 0);
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0)
                ec[s[i] - 'a']++;
            else
                oc[s[i] - 'a']++;
        }
        mxx = min(mxx, n / 2 - mx(ec) + n / 2 - mx(oc));

        for (int i = n - 2; i >= 0; i--) {
            if (i % 2 == 0) {
                ec[s[i] - 'a']--;
                ps1[s[i + 1] - 'a']++;
            } else {
                oc[s[i] - 'a']--;
                ps2[s[i + 1] - 'a']++;
            }
            vector<int> ps11(26, 0), ps22(26, 0);
            for (int j = 0; j < 26; j++) {
                ps11[j] = ec[j] + ps1[j];
                ps22[j] = oc[j] + ps2[j];
            }
            mxx = min(mxx, n / 2 - mx(ps11) + n / 2 - mx(ps22));
        }
        if(n<2)cout<<mxx+2<<endl;
        else
        cout<<mxx+1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}
