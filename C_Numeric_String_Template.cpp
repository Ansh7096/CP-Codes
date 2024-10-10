#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int m;
    cin >> m;

    while (m--) {
        string s;
        cin >> s;

        if (s.size() != v.size()) {
            cout << "NO" << endl;
            continue;
        }

        map<int, char> m1;
        map<char, int> m2;
        bool z = true;

        for (int i = 0; i < n; i++) {
            if (m2.count(s[i]) && m2[s[i]] != v[i]) {
                z = false;
                break;
            }
            if (m1.count(v[i]) && m1[v[i]] != s[i]) {
                z = false;
                break;
            }
            m2[s[i]] = v[i];
            m1[v[i]] = s[i];
        }

        if (z) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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
