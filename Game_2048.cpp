#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 998244353;
const int MAX_N = 1000001;

vector<long long> dp(17, 0);
int arr[MAX_N] = {0};

void solve() {
    long long n;
    cin >> n;
    if (n % 4 != 0) {
        cout << 0 << endl;
        return;
    }
    n /= 4;
    cout << arr[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // Precompute dp array
    dp[0] = 4;
    long long curr = 4;
    for (int i = 1; i < 17; i++) {
        curr *= 2;
        dp[i] = dp[i - 1] * 2 + curr;
    }
    for (int i = 0; i < 17; i++) {
        dp[i] /= 4;
    }

    // Precompute arr array
    arr[0] = 1;
    for (int i = 0; i < 17; i++) {
        int c = dp[i];
        for (int j = 0; j <= MAX_N - c; j++) {
            arr[j + c] = (arr[j + c] + arr[j]) % MOD;
        }
    }

    // Process test cases
    while (T--) {
        solve();
    }

    return 0;
}
