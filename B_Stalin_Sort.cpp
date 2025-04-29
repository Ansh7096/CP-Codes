#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
typedef long long ll;

int t;
ll n;
vector<ll> values;
unordered_map<ll, vector<ll>> graph;
map<ll, ll> maxSum;

ll findMaxSum(ll start) {
    if (maxSum.count(start)) return maxSum[start];
    ll result = start;

    if (graph.count(start)) {
        for (ll next : graph[start]) {
            ll new_start = start + next - 1;
            result = max(result, findMaxSum(new_start));
        }
    }

    return maxSum[start] = result;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        values.resize(n + 1);
        graph.clear();
        maxSum.clear();

        for (ll i = 1; i <= n; ++i) {
            cin >> values[i];
        }

        for (ll i = 2; i <= n; ++i) {
            ll indexSum = values[i] + i - 1;
            graph[indexSum].push_back(i);
        }

        cout << findMaxSum(n) << '\n';
    }
    return 0;
}
