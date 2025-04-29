// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

// Template Credits- Punpun018
/****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define intmin LLONG_MIN
#define intmax LLONG_MAX
#define ll long long
#define double long double
#define uint unsigned long long
#define inf 1000000000000000005
const long long mod = 998244353;
const ll N = 1e9 + 10;
const int MAX = 2000005;
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl "\n"
/**************************************************************************/

ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

bool is_valid(int x, int y, int N, int M)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int x, int y, vector<vector<bool>>& visited, const vector<string>& tiles, char color)
{
    stack<pair<int, int>> stack;
    stack.push({x, y});

    while (!stack.empty())
    {
        auto cx= stack.top().first;
        auto cy= stack.top().second;
        stack.pop();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
for (const auto& dir : directions)
{
    int nx = cx + dir.first, ny = cy + dir.second;
    if (is_valid(nx, ny, tiles.size(), tiles[0].size()) && !visited[nx][ny] && tiles[nx][ny] == color)
    {
        visited[nx][ny] = true;
        stack.push({nx, ny});
    }
}
    }
}

int count_initial_configurations(int N, int M, const vector<string>& tiles)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int component_count = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                dfs(i, j, visited, tiles, tiles[i][j]);
                ++component_count;
            }
        }
    }

    return expo(2, component_count, mod);
}

/**********************************************************************************************/

void sol()
{
    int N, M;
    cin >> N >> M;
    vector<string> tiles(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> tiles[i];
    }

    cout << count_initial_configurations(N, M, tiles) << endl;
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
