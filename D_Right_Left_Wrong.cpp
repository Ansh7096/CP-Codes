#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }

    string ss;
    cin >> ss;

    int l = 0, r = n - 1;
    int ans = 0;

    while (r >= l) {
       
        while (l <= r && ss[l] == 'R') {
            s -= v[l];
            l++;
        }

       
        while (l <= r && ss[r] == 'L') {
            s -= v[r];
            r--;
        }

        if (l > r) break;

      
        ans += s;
        s -= v[l];
        l++;
        s -= v[r];
        r--;
    }

    cout << ans << endl;
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
