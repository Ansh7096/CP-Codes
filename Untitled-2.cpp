#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int x, vector<int>& v) {
        long long ans = 0;
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int> vv(n, 0);
        int i = 0;
        
        // Distribute x among the elements
        while (x > 0) {
            vv[i]++;
            i++;
            x--;
            if (i == n) {
                i = 0;
            }
        }
        for(auto i:vv)cout<<i<<" ";
        cout<<endl;

        // Calculate the maximum time for any element
        for (int j = 0; j < n; j++) {
            long long c = 0;
            for (int k = 1; k <= vv[j]; k++) {
                c += v[j] * k;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x = 4;  
    vector<int> v = {2,1,1};  // example array

    cout << sol.minNumberOfSeconds(x, v) << endl;
    return 0;
}
