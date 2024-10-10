#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int calculate_typing_time(const string& s) {
    if (s.empty()) return 0;
    int time = 2; 
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

int main() {
    int t;
    cin >> t;
    vector<string> results(t);
    
    while (t--) {
        string s;
        cin >> s;
        string best_string = s;
        int max_time = calculate_typing_time(s);
        
      
        for (char c = 'a'; c <= 'z'; ++c) {
            for (size_t i = 0; i <= s.size(); ++i) {
                string new_string = s.substr(0, i) + c + s.substr(i);
                int new_time = calculate_typing_time(new_string);
                if (new_time > max_time) {
                    max_time = new_time;
                    best_string = new_string;
                }
            }
        }
        cout << best_string << endl;
    }
    
    return 0;
}
