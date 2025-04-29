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
        return gcd(b, a);
    if (b == 0)
        return a;
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
        b >>= 1;
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
}
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n], val2 = ifact[n - r], val3 = ifact[r];
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
    a %= m;
    b %= m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a %= m;
    b %= m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a %= m;
    b %= m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a %= m;
    b %= m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
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
}
/**********************************************************************************************/

bool theek(int i, unordered_map<int, int> m)
{
    for (int k = i; k < 10; k++)
    {

        bool z = false;
        for (int d = 9 - k; d <= 9; d++)
        {
            if (m[d] > 0)
            {
                m[d]--;
                z = true;
                break;
            }
        }
        if (!z)
            return false;
    }
    return true;
}

void sol()
{
    string s;
    cin >> s;
    unordered_map<int, int> m;
    for (char c : s)
        m[c - '0']++;
    string ans;
    ans.reserve(10);
    for (int i = 0; i < 10; i++)
    {
        for (int d = 9 - i; d <= 9; d++)
        {
            if (m[d] == 0)
                continue;
            m[d]--;
            if (theek(i + 1, m))
            {
                ans.push_back(char('0' + d));
                break;
            }
            m[d]++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}
