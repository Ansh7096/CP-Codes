#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        long long sum = 0;
        
        
       sum+=m-c;
       sum+=(n-r)*(m-1);
       sum+=(n-r)*m;
      cout<<sum<<endl; 
    }
    
    return 0;
}
