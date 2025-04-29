#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isSubsequenceSumK(const vector<int>& subarray, int k) {
    int n = subarray.size();
    vector<bool> dp(k + 1, false);
    dp[0] = true;

    for (int num : subarray) {
        for (int sum = k; sum >= num; --sum) {
            dp[sum] = dp[sum] || dp[sum - num];
        }
    }
    return dp[k];
}

int getSmallestSubarrayLength(int k, const vector<int>& amount) {
    int n = amount.size();
    int minLength = INT_MAX;
    
    for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
            vector<int> subarray(amount.begin() + left, amount.begin() + right + 1);
            if (isSubsequenceSumK(subarray, k)) {
                minLength = min(minLength, right - left + 1);
            }
        }
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> amount(n);
    for (int i = 0; i < n; ++i) {
        cin >> amount[i];
    }

    int result = getSmallestSubarrayLength(k, amount);
    cout << result << endl;

    return 0;
}
