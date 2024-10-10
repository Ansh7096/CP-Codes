#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s, t;
        cin >> s >> t;

        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j] || s[i] == '?') {
                // If characters match or s[i] is a question mark, move both pointers
                i++;
                j++;
            } else {
                // If characters don't match and s[i] is not a question mark, move only the t pointer
                j++;
            }
        }

        if (i == s.length()) {
            // All characters in s match or are replaced by question marks
            cout << "YES\n" << s << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
