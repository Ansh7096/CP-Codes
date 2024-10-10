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
    string s;
    cin >> n >> s;
    int z = sqrt(n);
    if (z * z != n)
    {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < z; i++)
    {
        if (s[i] != '1' || s[n - z + i] != '1')
        {
            cout << "No" << endl;
            return;
        }
    }

    for (int i = 1; i < z - 1; i++)
    {
        if (s[i*z] != '1' || s[i*z +z-1] != '1')
        {
            cout << "No" << endl;
            return;
        }

        for (int j = 1; j < z - 1; j++)
        {
            if (s[i * z + j] != '0')
            {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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