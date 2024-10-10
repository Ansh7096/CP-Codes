#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        string t;
        cin >> t;
        int n = t.size();
        int s = 1; // Initialize result to 1 as per the problem's requirement
        
        vector<int> p(n + 1);
        vector<int> e(2 * n + 2, 0); // Initialize to zero

        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] + (t[i] == '1' ? 1 : -1);
        }

        for (int j = 1; j <= n; ++j) {
            e[p[j - 1] + n] += j;
            e[p[j - 1] + n] %= MOD; // Ensure modulo at each addition
            s = (s + (long long)e[p[j] + n] * (n - j + 1)) % MOD;
        }

        cout << s - 1 << endl; // Output result, subtract 1 as per initial value setup
    }

    return 0;
}