#include <iostream>
#include <vector>
using namespace std;
using ll = long long;


ll calculateDistanceSquared(ll x1, ll y1, ll x2, ll y2) {
    ll deltaX = x2 - x1;
    ll deltaY = y2 - y1;
    return deltaX * deltaX + deltaY * deltaY;
}

int main() {
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        vector<ll> x(n), y(n); 
        for(ll i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        ll xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;

       
        ll originalDistance = calculateDistanceSquared(xs, ys, xd, yd);

        bool foundCloserPoint = false;

        for(ll i = 0; i < n; i++) {
          
            if(originalDistance >= calculateDistanceSquared(x[i], y[i], xd, yd)) {
                foundCloserPoint = true;
                break;
            }
        }

        if(foundCloserPoint) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
