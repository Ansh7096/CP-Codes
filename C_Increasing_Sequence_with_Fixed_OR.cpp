// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n;
    cin >> n;
    vector<int> v = {n};
    for (int i = 0; i < 61; i++)
    {
        if (n & (1LL << i))
        {
            if (n - (1LL << i) > 0)
            {
                v.push_back(n - (1LL << i));
            }
        }
    }
    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;
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