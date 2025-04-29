#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    int max_height = v[0]; 
    
    
    vector<int> z;
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(z.begin(), z.end(), v[i]);
            if (it == z.end()) z.push_back(v[i]);
            else *it = v[i];
        }

       
        cout << n - z.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}

