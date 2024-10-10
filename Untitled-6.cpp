#include <bits/stdc++.h>
using namespace std;

const int MAXN = 65536;

int parent[MAXN], depth[MAXN];
vector<int> tree[MAXN];
vector<int> pos_in_dfs;
int n, q;

void dfs(int v, vector<int>& dfs_order) {
    dfs_order.push_back(v);
    for (int u : tree[v]) {
        dfs(u, dfs_order);
    }
}

bool isValidDFSOrder(vector<int>& p) {
    vector<int> dfs_order;
    dfs(1, dfs_order);
    
    for (int i = 0; i < n; i++) {
        if (p[i] != dfs_order[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> q;
        
        for (int i = 2; i <= n; i++) {
            cin >> parent[i];
            tree[parent[i]].push_back(i);
        }
        
        vector<int> p(n);
        pos_in_dfs.resize(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            pos_in_dfs[p[i]] = i;
        }
        
        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            swap(p[x-1], p[y-1]);
            if (isValidDFSOrder(p))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
        }
    }
    
    return 0;
}
