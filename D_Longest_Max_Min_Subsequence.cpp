#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    unordered_map<int, int> last_occurrence;
    vector<int> longest_subseq;

    // Track the last occurrence of each element
    for (int i = 0; i < n; ++i) {
        last_occurrence[a[i]] = i;
    }

    vector<bool> included(n, false);
    
    // Build the longest subsequence from the end to the beginning
    for (int i = n - 1; i >= 0; --i) {
        if (!included[i]) {
            int idx = i;
            while (idx >= 0 && !included[idx]) {
                longest_subseq.push_back(a[idx]);
                included[idx] = true;
                idx = last_occurrence[a[idx]] - 1;
            }
        }
    }
    
    // Reverse the subsequence to get it in the correct order
    reverse(longest_subseq.begin(), longest_subseq.end());
    
    // Apply the sign transformation: odd indices (1-based) get negated
    for (int i = 0; i < longest_subseq.size(); ++i) {
        if (i % 2 == 0) {
            cout << -longest_subseq[i] << " ";
        } else {
            cout << longest_subseq[i] << " ";
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
