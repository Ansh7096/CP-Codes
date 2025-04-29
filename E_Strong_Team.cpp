#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to calculate nC3
long long comb3(int n) {
    if (n < 3) return 0;
    return (long long)n * (n - 1) * (n - 2) / 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> players(n);
        unordered_map<int, int> strength_count;
        unordered_map<int, int> endurance_count;

        for (int i = 0; i < n; ++i) {
            cin >> players[i].first >> players[i].second; // strength, endurance
            strength_count[players[i].first]++;
            endurance_count[players[i].second]++;
        }

        // Total combinations of picking 3 from n
        long long total_combinations = comb3(n);

        // Calculate invalid combinations
        long long invalid_combinations = 0;

        // Invalid combinations due to shared strengths
        for (const auto& pair : strength_count) {
            int count = pair.second;
            invalid_combinations += comb3(count);
        }

        // Invalid combinations due to shared endurances
        for (const auto& pair : endurance_count) {
            int count = pair.second;
            invalid_combinations += comb3(count);
        }

        // Valid combinations are total minus invalid
        long long valid_combinations = total_combinations - invalid_combinations;

        cout << valid_combinations << "\n";
    }

    return 0;
}