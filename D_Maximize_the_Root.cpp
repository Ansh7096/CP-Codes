#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
using namespace std;

#define ll long long
#define popcount(x) __builtin_popcountll(x)
#define inti unsigned long long  
using vi = vector<int>;
using vll = vector<ll>;
using mci = map<char, int>;
using mii = map<int, int>;
using mll = map<ll, ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const unsigned int M = 1000000007;
#define fl(i, a, n) for(int i = a; i < n; i++)
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(var) cout << var << endl;
#define vv(x) for(int i = 0; i < n; ++i){ll x; cin >> x; v.pb(x);}
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair
#define mod 998244353
#define double long double

void dfs(ll u, vector<vll>& adj, vector<ll>& a, vector<ll>& dp, ll& ans) {
    ll mx = LLONG_MAX;
    for (ll c : adj[u]) {
        dfs(c, adj, a, dp, ans);
        mx = min(mx, dp[c]);
    }

    if (mx == LLONG_MAX) {
        dp[u] = a[u];
    } else {
        if (a[u] >= mx) {
            dp[u] = mx;
        } else {
            dp[u] = (mx + a[u]) / 2;
        }
    }

    if (u == 0) {
        ans = a[0] + mx;
    }
}

void solve() {
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vll> adj(n);
    for (ll i = 0; i < n - 1; i++) {
        ll x;
        cin >> x;
        x--; 
        adj[x].pb(i + 1);
    }

    ll ans = 0;
    vector<ll> dp(n, LLONG_MAX);
    dfs(0, adj, a, dp, ans);
    cout << ans << endl;
}

int main() {
    optimize();
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}