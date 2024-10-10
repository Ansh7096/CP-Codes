#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int s, d, k;
        cin >> s >> d >> k;

        int total_buns = 2 * (s + d);
        int total_cheese = s + 2 * d;
        int total_patty = s + 2 * d;

        int required_buns = k + 1;
        int required_cheese = k;
        int required_patty = k;

        if (total_buns >= required_buns && total_cheese >= required_cheese && total_patty >= required_patty) {
            cout << "Case #" << i << ": YES" << endl;
        } else {
            cout << "Case #" << i << ": NO" << endl;
        }
    }
    return 0;
}
