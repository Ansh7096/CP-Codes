#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long mod = 998244353;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    vector<pair<int, vector<int>>> curr;
    
    // Start with individual elements
    for(int i = 0; i < n; i++) {
        if(a[i] == k) {
            cout << "YES" << endl;
            cout << 1 << endl;
            cout << i+1 << endl;
            return;
        }
        if(a[i] > k) {
            vector<int> temp = {i+1};
            curr.push_back({a[i], temp});
        }
    }
    
    // Try pairs and build up
    for(int len = 2; len <= min(20LL, n); len++) {
        vector<pair<int, vector<int>>> next;
        
        for(int j = 0; j < curr.size(); j++) {
            int val = curr[j].first;
            vector<int>& indices = curr[j].second;
            
            for(int i = indices.back(); i < n; i++) {
                int newVal = val & a[i];
                if(newVal == k) {
                    cout << "YES" << endl;
                    cout << len << endl;
                    for(int idx : indices)
                        cout << idx << " ";
                    cout << i+1 << endl;
                    return;
                }
                if(newVal > k) {
                    vector<int> newIndices = indices;
                    newIndices.push_back(i+1);
                    next.push_back({newVal, newIndices});
                }
            }
        }
        
        curr = next;
        if(curr.empty()) break;
    }
    
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}