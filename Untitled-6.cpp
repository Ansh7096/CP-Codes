// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> par(n, vector<char>(m, 'x'));

    pair<int, int> start, stort, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
                start = {i, j};
            else if (v[i][j] == 'B')
                end = {i, j};
        }
    }

    stort = start;
    vis[start.first][start.second] = true;
    queue<pair<int, int>> q;

   
    if (start.first + 1 < n && v[start.first + 1][start.second] != '#' && !vis[start.first + 1][start.second])
    {
        q.push({start.first + 1, start.second});
        vis[start.first + 1][start.second] = true;
        par[start.first + 1][start.second] = 'D';
    }

    if (start.first - 1 >= 0 && v[start.first - 1][start.second] != '#' && !vis[start.first - 1][start.second])
    {
        q.push({start.first - 1, start.second});
        vis[start.first - 1][start.second] = true;
        par[start.first - 1][start.second] = 'U'; 
    }

    if (start.second + 1 < m && v[start.first][start.second + 1] != '#' && !vis[start.first][start.second + 1])
    {
        q.push({start.first, start.second + 1});
        vis[start.first][start.second + 1] = true;
        par[start.first][start.second + 1] = 'R';
    }

    if (start.second - 1 >= 0 && v[start.first][start.second - 1] != '#' && !vis[start.first][start.second - 1])
    {
        q.push({start.first, start.second - 1});
        vis[start.first][start.second - 1] = true;
        par[start.first][start.second - 1] = 'L'; 
    }

    
    while (!q.empty() && q.front() != end)
    {
        start = q.front();
        q.pop();

        if (start.first + 1 < n && v[start.first + 1][start.second] != '#' && !vis[start.first + 1][start.second])
        {
            q.push({start.first + 1, start.second});
            vis[start.first + 1][start.second] = true;
            par[start.first + 1][start.second] = 'D'; 
        }

        if (start.first - 1 >= 0 && v[start.first - 1][start.second] != '#' && !vis[start.first - 1][start.second])
        {
            q.push({start.first - 1, start.second});
            vis[start.first - 1][start.second] = true;
            par[start.first - 1][start.second] = 'U'; 
        }

        if (start.second + 1 < m && v[start.first][start.second + 1] != '#' && !vis[start.first][start.second + 1])
        {
            q.push({start.first, start.second + 1});
            vis[start.first][start.second + 1] = true;
            par[start.first][start.second + 1] = 'R';
        }

        if (start.second - 1 >= 0 && v[start.first][start.second - 1] != '#' && !vis[start.first][start.second - 1])
        {
            q.push({start.first, start.second - 1});
            vis[start.first][start.second - 1] = true;
            par[start.first][start.second - 1] = 'L';
        }
    }

    // Check if we reached the end
    if (!q.empty() && q.front() == end)
    {
        cout << "YES" << endl;

       
        string path;
        pair<int, int> current = end;
        while (current != stort)
        {
            char direction = par[current.first][current.second];
            path.push_back(direction);

            if (direction == 'U')
                current.first += 1;
            else if (direction == 'D')
                current.first -= 1;
            else if (direction == 'L')
                current.second += 1;
            else if (direction == 'R')
                current.second -= 1;
        }

        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }
    else
        cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        sol();
    }
}
