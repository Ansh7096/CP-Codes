#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sol() {
    int i, n, j, k, ct = 0, ind = 0, ans, sum = 0, val, x, y;
    cin >> n;
    vector<int> even, odd;
    
    for (i = 0; i < n; i++) {
        cin >> x;
        if (x & 1) 
            odd.push_back(x);
        else 
            even.push_back(x);
    }
    
    if (even.empty()) {
        cout << 0 << endl;
        return;
    }
    if (odd.empty()) {
        cout << 0 << endl;
        return;
    }
    
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    
    val = odd.back();
    
    for (i = 0; i < even.size(); i++) {
        if (val > even[i]) {
            val += even[i];
            sum++;
        } else {
            cout << (2 + even.size() - 1)<< endl;
            return;
            
        }
    }
    
    cout << sum << endl;
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        sol();
    }
    return 0;
}
