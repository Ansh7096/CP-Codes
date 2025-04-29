#include <iostream>
#include <vector>
using namespace std;

bool checkValid(const vector<int>& arr, int L, int R, int m) {
    int minVal = arr[L - 1];
    for (int i = L - 1; i < R; i++) {
        minVal = min(minVal, arr[i]);
    }
    return minVal != m;
}

bool solve() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<pair<int, int>, int>> constraints(K);
    for (int i = 0; i < K; i++) {
        cin >> constraints[i].first.first >> constraints[i].first.second >> constraints[i].second;
    }
    
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    
   
    bool valid = true;
    for (const auto& constraint : constraints) {
        int L = constraint.first.first;
        int R = constraint.first.second;
        int m = constraint.second;
        
        if (!checkValid(arr, L, R, m)) {
            valid = false;
            break;
        }
    }
    
    
    if (valid) {
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
        return true;
    }
    

    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }
    
    valid = true;
    for (const auto& constraint : constraints) {
        int L = constraint.first.first;
        int R = constraint.first.second;
        int m = constraint.second;
        
        if (!checkValid(arr, L, R, m)) {
            valid = false;
            break;
        }
    }
    

    if (valid) {
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
        return true;
    }
    
    
    cout << "-1" << endl;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}