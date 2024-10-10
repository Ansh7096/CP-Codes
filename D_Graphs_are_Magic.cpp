// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 100005;
const int MOD = 1000000007;

struct Edge {
    int to, w;
};

vector<Edge> adj[N];
int parent[N], depth[N], heavy[N], head[N], pos[N];
int segtree[4 * N], value[N];
int current_pos;
int max_edge[N][20]; 
int ancestor[N][20]; 

int dfs(int v) {
    int size = 1;
    int max_subtree = 0;
    for (auto &edge : adj[v]) {
        int u = edge.to;
        if (u == parent[v]) continue;
        parent[u] = v;
        depth[u] = depth[v] + 1;
        max_edge[u][0] = edge.w;
        ancestor[u][0] = v;
        int subtree_size = dfs(u);
        if (subtree_size > max_subtree) {
            max_subtree = subtree_size;
            heavy[v] = u;
        }
        size += subtree_size;
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = current_pos++;
    if (heavy[v] != -1) decompose(heavy[v], h);
    for (auto &edge : adj[v]) {
        int u = edge.to;
        if (u != parent[v] && u != heavy[v]) decompose(u, u);
    }
}

void build_segtree(int node, int start, int end) {
    if (start == end) {
        segtree[node] = value[start];
    } else {
        int mid = (start + end) / 2;
        build_segtree(2 * node, start, mid);
        build_segtree(2 * node + 1, mid + 1, end);
        segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
    }
}

void update_segtree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        segtree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update_segtree(2 * node, start, mid, idx, val);
        } else {
            update_segtree(2 * node + 1, mid + 1, end, idx, val);
        }
        segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
    }
}

int query_segtree(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return -1;
    }
    if (l <= start && end <= r) {
        return segtree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query_segtree(2 * node, start, mid, l, r);
    int p2 = query_segtree(2 * node + 1, mid + 1, end, l, r);
    return max(p1, p2);
}

int query(int a, int b) {
    int res = -1;
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]]) swap(a, b);
        res = max(res, query_segtree(1, 0, current_pos - 1, pos[head[b]], pos[b]));
        b = parent[head[b]];
    }
    if (a != b) {
        if (depth[a] > depth[b]) swap(a, b);
        res = max(res, query_segtree(1, 0, current_pos - 1, pos[a] + 1, pos[b]));
    }
    return res;
}

void preprocess_lifting(int n) {
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (ancestor[i][j-1] != -1) {
                ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
                max_edge[i][j] = max(max_edge[i][j-1], max_edge[ancestor[i][j-1]][j-1]);
            }
        }
    }
}

int max_edge_query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int res = -1;

    for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            res = max(res, max_edge[u][i]);
            u = ancestor[u][i];
        }
    }

    if (u == v) return res;

    for (int i = 19; i >= 0; i--) {
        if (ancestor[u][i] != ancestor[v][i]) {
            res = max(res, max_edge[u][i]);
            res = max(res, max_edge[v][i]);
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }

    return max(res, max(max_edge[u][0], max_edge[v][0]));
}

void sol() {
    int n;
    cin >> n;
    current_pos = 0;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        heavy[i] = -1;
        parent[i] = -1;
        depth[i] = 0;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
    }

    dfs(1);
    decompose(1, 1);
    preprocess_lifting(n);

    for (auto &e : edges) {
        int u = e.second.first, v = e.second.second, w = e.first;
        if (parent[u] == v) swap(u, v);
        value[pos[v]] = w;
    }
    build_segtree(1, 0, current_pos - 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += max_edge_query(i, j);
            if (ans >= MOD) ans -= MOD;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}
