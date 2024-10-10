#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Function to calculate the sum of f(i) for i = 0 to m
long long calculateSumOfF(int n, long long m, vector<vector<int>>& sequences) {
    set<int> all_mex_values;
    for (const auto& seq : sequences) {
        set<int> unique_elements(seq.begin(), seq.end());
        int mex_value = 0;
        while (unique_elements.count(mex_value)) {
            ++mex_value;
        }
        all_mex_values.insert(mex_value);
    }

    // Find the maximum mex_value we can get
    int max_mex = *all_mex_values.rbegin();
    
    // If m < max_mex, just sum up m+1 * max_mex
    if (m < max_mex) {
        return static_cast<long long>(m + 1) * max_mex;
    }

    // Otherwise, we need to sum up to max_mex and then add the remaining
    long long sum = static_cast<long long>(max_mex) * (max_mex + 1) / 2;
    sum += max_mex * (m - max_mex + 1);
    return sum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;
        
        vector<vector<int>> sequences(n);
        for (int i = 0; i < n; ++i) {
            int len;
            cin >> len;
            sequences[i].resize(len);
            for (int j = 0; j < len; ++j) {
                cin >> sequences[i][j];
            }
        }
        
        cout << calculateSumOfF(n, m, sequences) << endl;
    }
    
    return 0;
}
