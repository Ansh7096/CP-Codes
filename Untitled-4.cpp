#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pods(n), cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> pods[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

   
    vector<pair<int, int>> services;
    for (int i = 0; i < n; ++i) {
        services.push_back({pods[i], cost[i]});
    }
    sort(services.begin(), services.end());

    set<int> distinctPods;
    int totalCost = 0;

    for (const auto& service : services) {
        int currPods = service.first;
        int currCost = service.second;

        if (distinctPods.count(currPods)) {
           
            ++currPods;
            totalCost += currCost;
        }

        distinctPods.insert(currPods);
    }

    cout << totalCost << endl;
    return 0;
}
