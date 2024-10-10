#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int max_score = 0;
        
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) {
                int left_ops = k;
                int left_addition = min(k, left_ops);
                int potential_score = a[i] + left_addition;
                vector<int> c = a;
                c.erase(c.begin() + i);
                sort(c.begin(), c.end());
                int median = c[(n - 2) / 2];
                max_score = max(max_score, potential_score + median);
            }
        }
        
        cout << max_score << endl;
    }
    
    return 0;
}
