// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> v(2 * N);
    for (int i = 0; i < N; i++)
    {
        v[i] = A[i];
        v[i + N] = A[i];
    }

    vector<int> ps(2 * N + 1, 0);
    for (int i = 1; i <= 2 * N; ++i)
    {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    for (int i = 0; i <= 2 * N; i++)
        ps[i] %= M;

    map<int, int> mp;
    map<int, int> m;

    int ans = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < N; i++)
    {
        r = i;
        if (r - l >= N)
        {
            mp[ps[l]]--;
            l++;
        }
        ans += mp[ps[r]];
        mp[ps[r]]++;
    }
    int a2 = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        r = i;
        if (r - l >= N)
        {
            m[ps[l]]--;
            l++;
        }
        a2 += m[ps[r]];
        m[ps[r]]++;
    }
    cout << a2 - ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        sol();
    }
}