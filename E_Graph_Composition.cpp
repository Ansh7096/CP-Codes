#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

pair<int, vector<int>> dfs(vector<vector<int>>& adj, int n) {
    vector<int> vis(n + 1, 0);
    int component_count = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            component_count++;
            stack<int> st;
            st.push(i);

            while (!st.empty()) {
                int u = st.top();
                st.pop();

                if (vis[u] != 0)
                    continue;
                vis[u] = component_count;

                for (int v : adj[u]) {
                    if (vis[v] == 0)
                        st.push(v);
                }
            }
        }
    }

    return {component_count, vis};
}

void sol() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<vector<int>> v1(n + 1), v2(n + 1);
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        v1[u].push_back(v);
        v1[v].push_back(u);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        v2[u].push_back(v);
        v2[v].push_back(u);
    }

    auto a1 = dfs(v1, n);
    auto a2 = dfs(v2, n);

    vector<int> vis1 = a1.second;
    vector<int> vis2 = a2.second;

    vector<pair<int, int>> new_edges;

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (vis1[u] != vis1[v] && vis2[u] != vis2[v]) {
                new_edges.push_back({u, v});

                // Merge the components in vis1
                int old_comp = vis1[v];
                for (int i = 1; i <= n; i++) {
                    if (vis1[i] == old_comp) {
                        vis1[i] = vis1[u];
                    }
                }
            }
        }
    }

    cout << new_edges.size() << endl;
    for (auto ii: new_edges) {
        cout << ii.first  << " " << ii.second << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }

    return 0;
}
