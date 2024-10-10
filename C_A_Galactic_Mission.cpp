#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// Function to get number of substrings of a given length with specific pattern
int calc(string& s, int p, int q) {
    int len = q - p;
    int result = 0;
    
    // Iterate over substrings and calculate result
    for (int i = p; i < q; i++) {
        if (s[i] == '1') {
            result += (len - (i - p)) / 2 + 1;
        } else {
            result += (len - (i - p) + 1) / 2;
        }
    }
    return result;
}

// Helper function to calculate prefix sums
vector<int> prefixSum(const string& s, char c) {
    vector<int> ps(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        ps[i + 1] = ps[i] + (s[i] == c);
    }
    return ps;
}

void sol() {
    string s;
    cin >> s;
    int n = s.size();

    // Prefix sums for '1' and '0'
    vector<int> ps1 = prefixSum(s, '1');
    vector<int> ps0 = prefixSum(s, '0');

    int ans = 0;
    for (int p = 0; p < n; p++) {
        for (int q = p + 1; q <= n; q++) {
            int ones = ps1[q] - ps1[p];
            int zeros = ps0[q] - ps0[p];
            int len = q - p;
            ans += (ones + zeros) * (len - 1) / 2;
        }
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
    return 0;
}
