#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Create a priority queue to store pairs of (profit, index)
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({a[i], i});
        }

        long long max_score = 0;
        while (k > 0 && !pq.empty()) {
            auto [score_gain, index] = pq.top();
            pq.pop();

            if (score_gain == 0) break;

            max_score += score_gain;
            a[index] = max(0 , a[index] - b[index]);

            pq.push({a[index], index});
            k--;
        }
        cout << max_score << endl;
    }
    return 0;
}
