#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int q(int a, int b) {
    cout << "? " << a << " " << b << endl;
    fflush(stdout);
    int r;
    cin >> r;
    return r;
}

void sol() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << "! 1 2" << endl;
        fflush(stdout);
        return;
    }

    vector<int> vis(n + 1, 0);
    vector<pair<int, int>> edges;

    vector<int> dist(n + 1, -1);


    for (int i = 2; i <= n; ++i) {
        int res = q(1, i);
        dist[i] = res;
    }
    vector<int> nodes(n - 1);
    iota(nodes.begin(), nodes.end(), 2);

    sort(nodes.begin(), nodes.end(), [&](int a, int b) {
        return dist[a] < dist[b];
    });

    
    for (size_t i = 0; i < nodes.size(); ++i) {
        int a = nodes[i];
        for (size_t j = i + 1; j < nodes.size(); ++j) {
            int b = nodes[j];
            int res = q(a, b);
            if (res == a || res == b) {
                edges.push_back({a, b});
                vis[a] = 1;
                vis[b] = 1;
                break;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (vis[i] == 0) {
            for (int j = 1; j < i; ++j) {
                if (vis[j] == 1) {
                    edges.push_back({i, j});
                    vis[i] = 1;
                    break;
                }
            }
        }
    }

    cout << "!";
    for (const auto& e : edges) {
        cout << " " << e.first << " " << e.second;
    }
    cout << endl;
    fflush(stdout);
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
