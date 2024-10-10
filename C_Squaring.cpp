#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int operations = 0;
        bool possible = true;
        
        for (int i = 1; i < n; ++i) {
            while (a[i] < a[i - 1]) {
                a[i] *= a[i];
                ++operations;

                if (a[i] < a[i - 1] && a[i] == 1) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }

        if (possible) {
            cout << operations << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
