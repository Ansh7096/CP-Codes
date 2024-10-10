#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        vector<int> s;
        for (int i = l; i <= r; ++i) {
            s.push_back(i);
        }

        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (__gcd(s[i], s[j]) == 1 && __gcd(s[j], s[k]) == 1 && __gcd(s[i], s[k]) == 1) {
                        // Remove the three elements
                        s.erase(s.begin() + k);
                        s.erase(s.begin() + j);
                        s.erase(s.begin() + i);
                        n -= 3;
                        count++;
                        // Restart the loop after removing elements
                        i = -1;
                        break;
                    }
                }
                if (i == -1) break;
            }
        }

        cout << count << endl;
    }
    return 0;
}
