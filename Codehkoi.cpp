#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());

        bool ok = false;

        for (int i = 0, j; i < n; i = j)
        {
            j = i;
            while (j < n && a[j] == a[i])
                ++j;
            if (j - i >= 4)
            {
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            vector<pair<long long, int>> v;
            for (int i = 0, j; i < n; i = j)
            {
                j = i;
                while (j < n && a[j] == a[i])
                    ++j;
                v.push_back({a[i], j - i});
            }

            for (size_t l = 0; l < v.size() && !ok;)
            {
                size_t r = l;
                int two = v[l].second >= 2;
                while (r + 1 < v.size() && v[r + 1].first == v[r].first + 1)
                {
                    ++r;
                    if (v[r].second >= 2)
                        ++two;
                }
                if (two >= 2)
                    ok = true;
                l = r + 1;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
        return 0;
}