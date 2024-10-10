
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

void process_test_case() {
    ll len;
    cin >> len;

    if (len % 2 == 0) 
        cout << -1 << nl;
     else {
        for (ll i = len; i > 0; i -= 2) 
            cout << i << " ";
        
        for (ll i = 2; i < len; i += 2) 
            cout << i << " ";
        
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll test_cases;
    cin >> test_cases;
    while (test_cases--) {
        process_test_case();
    }
}
