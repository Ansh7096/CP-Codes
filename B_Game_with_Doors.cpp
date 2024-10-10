
#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > b or a > d)
    {
        cout << 1 << endl;
        return;
    }
    if (c < a)
    {
        swap(a, c);
        swap(b, d);
    }

    int ans = 0;
    map<int, int> m;
    for (int i = a; i <= b; i++)
    {
        m[i]++;
    }
    for (int i = c; i <= d; i++)
    {
        m[i]++;
    }
    int l = -1;
    int r = -1;
    for (int i = 1; i <= 100; i++)
    {
        if (m[i] == 2)
        {
            ans++;
            if (l == -1)
            {
                l = i;
            }
            r = i;
        }
    }
    ans--;
    if (min({a, b, c, d}) < l)
    {
        ans++;
    }
    if (max({a, b, c, d}) > r)
    {
        ans++;
    }
    cout << ans << endl;
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