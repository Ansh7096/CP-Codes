// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<vector<int>> adj;
vector<bool> vis;
vector<int> d, p;
void sol()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    //p.assign(n + 1,-1);
    d.assign(n + 1, 0);
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    vis[1] = true;
    //p[1] = -1;
    p.push_back(1);
    while (!q.empty())
    {
       auto it = q.top();
       q.pop();
       
       
       if (it.second == n) break;
       for (int node : adj[it.second]) {
        if (!vis[node]) {
            q.push({it.first + 1, node});
            
            vis[node] = 1;
            }
       }

    }
    if (!vis[n])
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout<<p.size()<<endl;
        
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
     t = 1;
    //cin >> t;
    while (t--)
    {
        sol();
    }
}