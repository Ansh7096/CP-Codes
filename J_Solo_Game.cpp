#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 300000;

int getMaxScore(vector<int>& blocks, int N) {
    // dp[i][j] will store the maximum score for the range blocks[i] to blocks[j]
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Fill dp table in bottom-up manner
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;

            // If blocks[i] == blocks[j], we can remove both ends and add the score
            if (blocks[i] == blocks[j]) {
                dp[i][j] = dp[i + 1][j - 1] + len - 1;
            }

            // Try to split the array into two parts and maximize score
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    return dp[0][N - 1];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> blocks(N);

        for (int i = 0; i < N; i++) {
            cin >> blocks[i];
        }

        cout << getMaxScore(blocks, N) << endl;
    }

    return 0;
}
