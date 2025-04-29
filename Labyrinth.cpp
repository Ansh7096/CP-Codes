// // AG___
// // There is a one percent chance, and sometimes that chance is good enough.
// // But what matters is what you think about that one percent.

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// void sol()
// {
//     int n, m;
//     cin >> n >> m;
//     // cout << n << m << endl;
//     vector<vector<char>> v(n, vector<char>(m));
//     vector<vector<bool>> vis(n, vector<bool>(m, false));
//     vector<vector<char>> par(n, vector<char>(m));
//     pair<int, int> start, stort;
//     pair<int, int> end;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> v[i][j];
//             if (v[i][j] == 'A')
//                 start = {i, j};
//             else if (v[i][j] == 'B')
//                 end = {i, j};
//         }
//     }
//     stort = start;
//     // cout << n << m << endl;
//     vis[start.first][start.second] = true;
//     queue<pair<int, int>> q;
//     q.push(start);
//     // if (start.first + 1 < n && v[start.first + 1][start.second] != '#' && !vis[start.first + 1][start.second])
//     // {
//     //     q.push({start.first + 1, start.second});
//     //     vis[start.first + 1][start.second] = true;
        
//     //         par[start.first + 1][start.second] = 'D';
//     // }
//     // if (start.first - 1 >= 0 && v[start.first - 1][start.second] != '#' && !vis[start.first - 1][start.second])
//     // {
//     //     q.push({start.first - 1, start.second});
//     //     vis[start.first - 1][start.second] = true;
        
//     //         par[start.first - 1][start.second] = 'U';
//     // }
//     // if (start.second + 1 < m && v[start.first][start.second + 1] != '#' && !vis[start.first][start.second + 1])
//     // {
//     //     q.push({start.first, start.second + 1});
//     //     vis[start.first][start.second + 1] = true;
        
//     //         par[start.first][start.second + 1] = 'R';
//     // }
//     // if (start.second - 1 >= 0 && v[start.first][start.second - 1] != '#' && !vis[start.first][start.second - 1])
//     // {
//     //     q.push({start.first, start.second - 1});
//     //     vis[start.first][start.second - 1] = true;
        
//     //         par[start.first][start.second - 1] = 'L';
//     // }
//     while (!q.empty() && q.front() != end)
//     {
//         // cout << start.first << " " << start.second << endl;
//         start = q.front();
//         q.pop();
//         if (start.first + 1 < n && v[start.first + 1][start.second] != '#' && !vis[start.first + 1][start.second])
//         {
//             q.push({start.first + 1, start.second});
//             vis[start.first + 1][start.second] = true;
          
//                 par[start.first + 1][start.second] = 'D';
//         }
//         if (start.first - 1 >= 0 && v[start.first - 1][start.second] != '#' && !vis[start.first - 1][start.second])
//         {
//             q.push({start.first - 1, start.second});
//             vis[start.first - 1][start.second] = true;
          
//                 par[start.first - 1][start.second] = 'U';
//         }
//         if (start.second + 1 < m && v[start.first][start.second + 1] != '#' && !vis[start.first][start.second + 1])
//         {
//             q.push({start.first, start.second + 1});
//             vis[start.first][start.second + 1] = true;
           
//                 par[start.first][start.second + 1] = 'R';
//         }
//         if (start.second - 1 >= 0 && v[start.first][start.second - 1] != '#' && !vis[start.first][start.second - 1])
//         {
//             q.push({start.first, start.second - 1});
//             vis[start.first][start.second - 1] = true;
            
//                 par[start.first][start.second - 1] = 'L';
//         }
//     }
//     // start = q.front();
//     // cout << start.first << " " << start.second << endl;

//     if (!q.empty() && q.front() == end)
//     {
//         cout << "YES" << endl;
//         string path;
//         pair<int, int> current = end;
//         while (current != stort)
//         {
//             char direction = par[current.first][current.second];
//             path.push_back(direction);

//             if (direction == 'U')
//                 current.first += 1;
//             else if (direction == 'D')
//                 current.first -= 1;
//             else if (direction == 'L')
//                 current.second += 1;
//             else if (direction == 'R')
//                 current.second -= 1;
//         }

//         reverse(path.begin(), path.end());
//         cout << path.size() << endl;
//         cout << path << endl;
//     }
//     else
//         cout << "NO" << endl;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         // cout << "hi" << endl;
//         sol();
//     }
// }
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
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
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
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
/**********************************************************************************************/



void sol() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    vector<vector<char>> dir(n, vector<char>(m));
    pair<int, int> start, end;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') start = {i, j};
            else if (v[i][j] == 'B') end = {i, j};
        }
    }

    
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    
    int drow[] = {1, -1, 0, 0};
    int dcol[] = {0, 0, 1, -1};
    char mov[] = {'D', 'U', 'R', 'L'};

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int row = it.first, col = it.second;
        //cout<<row<<" "<<col<<endl;
        
        if (row == end.first && col == end.second) {
            string s = "";
            while (!(row == start.first && col == start.second)) {
                s += dir[row][col];
                tie(row, col) = par[row][col];  
            }
            reverse(s.begin(), s.end());  
            cout << "YES\n";
            cout << s.size() << "\n";
            cout << s << "\n";
            return;
        }

        
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i], ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && v[nrow][ncol] != '#') {
                vis[nrow][ncol] = true;
                par[nrow][ncol] = {row, col};  
                dir[nrow][ncol] = mov[i];      
                q.push({nrow, ncol});
            }
        }
    }

    
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    
    while (t--) {
        sol();
    }
}
