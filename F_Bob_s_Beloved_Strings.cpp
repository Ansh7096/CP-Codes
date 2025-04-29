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

const int MOD = 998244353;
const int MAXN = 200101;

vector<int> f(MAXN), inv(MAXN), freq(MAXN);
vector<int> bit(MAXN);

int fastpow(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = 1LL * result * base % MOD;
        base = 1LL * base * base % MOD;
        exp /= 2;
    }
    return result;
}

void addBIT(int idx, int value)
{
    for (; idx < MAXN; idx += idx & -idx)
    {
        bit[idx] = (bit[idx] + value) % MOD;
    }
}

int sumBIT(int idx)
{
    int result = 0;
    for (; idx > 0; idx -= idx & -idx)
    {
        result = (result + bit[idx]) % MOD;
    }
    return result;
}

void sol()
{
    int n, m;
    cin >> n >> m;

    vector<int> s(n), t(m);

    f[0] = 1;
    for (int i = 1; i < MAXN; i++)
        f[i] = 1LL * f[i - 1] * i % MOD;
    
    inv[MAXN - 1] = fastpow(f[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; --i)
    {
        inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        freq[s[i]]++;
    }

    for (int i = 0; i < m; i++)
        cin >> t[i];

    for (int i = 1; i < MAXN; i++)
        addBIT(i, freq[i]);

    int answer = 0;
    int F = 1;

    for (int i = 1; i < MAXN; i++)
        F = 1LL * F * inv[freq[i]] % MOD;

    for (int i = 0; i < n && i < m; i++)
    {
        answer = (answer + 1LL * f[n - i - 1] * F % MOD * sumBIT(t[i] - 1)) % MOD;

        if (freq[t[i]] == 0)
            break;

        addBIT(t[i], -1);
        F = 1LL * F * freq[t[i]] % MOD;
        freq[t[i]]--;

        if (i == n - 1 && i < m - 1)
        {
            answer = (answer + 1) % MOD;
        }
    }

    cout << answer << endl;
}

signed main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        sol();
    return 0;
}
