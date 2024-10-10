#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Initialize variables
    int currPos = 0; // Current position
    int timeSpent = 0; // Time spent
    int maxDelay = 0; // Maximum delay

    // Simulate Robin's movement
    for (char c : s) {
        if (c == '(') {
            currPos++; // Move right
        } else {
            currPos--; // Move left
        }

        // Update time spent
        timeSpent++;

        // Update maximum delay
        maxDelay = max(maxDelay, timeSpent - currPos);
    }

    // Print the maximum delay
    cout << maxDelay << endl;

    return 0;
}
