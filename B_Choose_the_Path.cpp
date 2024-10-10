#include <iostream>
using namespace std;

// Function to compute minimal sum of costs
long long minimal_sum(int n, int m) {
    long long total_cells = (long long)n * m;
    long long total_sum = total_cells * (total_cells + 1) / 2;
    long long max_path_sum = (long long)(2 * total_cells - (n + m - 1)) * (n + m - 1) / 2;
    return total_sum - max_path_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << minimal_sum(n, m) << '\n';
    }

    return 0;
}
