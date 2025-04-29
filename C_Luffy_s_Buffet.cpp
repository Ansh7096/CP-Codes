#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    // Store indices of each tastiness level
    vector<int> ones, twos, threes;
    for (int i = 0; i < N; ++i) {
        if (T[i] == 1) ones.push_back(i);
        else if (T[i] == 2) twos.push_back(i);
        else if (T[i] == 3) threes.push_back(i);
    }

    vector<tuple<int, int, int>> results;

    // Two-pointer technique to find valid (1, 2, 3) or (3, 2, 1) triplets
    for (int b : twos) {  // Iterate over each index of tastiness level 2
        // Find valid 'a' from 'ones' that is less than 'b'
        auto it1 = lower_bound(ones.begin(), ones.end(), b);
        if (it1 != ones.begin()) {
            --it1;
            int a = *it1;

            // Find valid 'c' from 'threes' that is greater than 'b'
            auto it3 = upper_bound(threes.begin(), threes.end(), b);
            if (it3 != threes.end()) {
                int c = *it3;
                results.emplace_back(a, b, c);
            }
        }

        // Find valid 'a' from 'threes' that is less than 'b'
        it1 = lower_bound(threes.begin(), threes.end(), b);
        if (it1 != threes.begin()) {
            --it1;
            int a = *it1;

            // Find valid 'c' from 'ones' that is greater than 'b'
            it3 = upper_bound(ones.begin(), ones.end(), b);
            if (it3 != ones.end()) {
                int c = *it3;
                results.emplace_back(a, b, c);
            }
        }
    }

    // Output the results
    cout << results.size() << endl;
    for (const auto& [a, b, c] : results) {
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}
