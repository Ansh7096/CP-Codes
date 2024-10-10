#include <iostream>
#include <vector>
using namespace std;

void constructGoodArray(int n, vector<int>& b) {
    vector<int> a(n, 0);

    for (int bit = 30; bit >= 0; --bit) {
        int mask = 1 << bit;
        bool found = false;

        for (int i = 0; i < n - 1; ++i) {
            if (b[i] & mask) {
                a[i] |= mask;
                a[i + 1] |= mask;
                found = true;
            }
        }

        if (!found) {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> b[i];
        }
        constructGoodArray(n, b);
    }

    return 0;
}
