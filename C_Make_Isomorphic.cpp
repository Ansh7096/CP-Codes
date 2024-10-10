// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int N;
vector<vector<int>> G, H, A;

void sol() {
    cin >> N;
    int mg;
    cin >> mg;
   
    G.assign(N, vector<int>(N, 0));
    H.assign(N, vector<int>(N, 0));
    A.assign(N, vector<int>(N, 0));

    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        G[u][v] = G[v][u] = 1;
    }
    
    int mh;
    cin >> mh;
   
    for (int i = 0; i < mh; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        H[a][b] = H[b][a] = 1;
    }
   
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int cost;
            cin >> cost;
            A[i][j] = A[j][i] = cost;
        }
    }
    
    int ans = LLONG_MAX;
    vector<int> vv(N);
    for (int i = 0; i < N; i++) vv[i] = i;
    
    bool z = true;
    while (z) {
        int tc = 0;
        for (int i = 0; i < N; i++) {
            int u = i;
            for (int j = i + 1; j < N; ++j) {
                int v = j;
                int gz = G[u][v];
                int hz = H[vv[u]][vv[v]];
                if (gz != hz) {
                    int a = min(vv[u], vv[v]);
                    int b = max(vv[u], vv[v]);
                    tc += A[a][b];
                }
            }
        }
       
        if (tc < ans) {
            ans = tc;
        }
        
        z = next_permutation(vv.begin(), vv.end());
    }
   
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
}
