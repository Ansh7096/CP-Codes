#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int countA = 0, countB = 0, countC = 0, countD = 0;
        
        for (char c : s) {
            if (c == 'A') countA++;
            else if (c == 'B') countB++;
            else if (c == 'C') countC++;
            else if (c == 'D') countD++;
           
        }
        
        cout<<min(countA,n)+min(countB,n)+min(countC,n)+min(countD,n)<<endl;
    }
    
    return 0;
}
