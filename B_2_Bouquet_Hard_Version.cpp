// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol() {
    int n, b;
    cin >> n >> b;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];
    map<int, int> pq;
    for (int i = 0; i < n; i++) pq[p[i]] = q[i];

    int ans = 0;
    for (auto it = pq.begin(); it != pq.end(); it++) {
        int z1 = it->first, z2 = it->second;
        int nq = (pq.find(z1 + 1) != pq.end()) ? pq[z1 + 1] : 0;
        int ct = min(z2, b / z1), rb = b - ct * z1, total = 0;

        if (nq > 0) {
            total = min(nq, rb / (z1 + 1));
            rb -= total * (z1 + 1);
        }
        ans = max(ans, ct * z1 + total * (z1 + 1));

        int ln = nq - total, lb = rb, cr = min(min(ct, lb), ln);
        ct -= cr; total += cr;
        ans = max(ans, ct * z1 + total * (z1 + 1));
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //t = 1;
    cin>>t;
    while (t--)
    {
        sol();
    }
}