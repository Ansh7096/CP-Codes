// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<vector<int>> adj;
vector<int> pro_by;
vector<int> dis;
bool bfs(int k, int s, int id)
{
    queue<pair<int, int>> q;
    q.push({k, 0});
    if(pro_by[k]!=0)return false;
    pro_by[k] = id;
    dis[k] = 0;

    while (!q.empty())
    {
        int city = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist == s)
            continue;

        for (int u : adj[city])
        {
            if (dis[u] == -1)
            {
                pro_by[u] = id;
                dis[u] = dist + 1;
                q.push({u, dist + 1});
            }
            else if (pro_by[u] != id)
                return false;
        }
    }
    return true;
}
void sol()
{
    int n, r, m;
    cin >> n >> r >> m;
    adj.assign(n + 1, vector<int>());
    pro_by.assign(n + 1, 0);
    dis.assign(n + 1, -1);

    for (int i = 0; i < r; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool z = true;
    for (int i = 0; i < m; i++)
    {
        int k, s;
        cin >> k >> s;
        if (!bfs(k, s, i + 1))
        {
            z = false;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == -1)
        {
            z = false;
            break;
        }
    }
    if (z)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
}