// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int m = 1e9 + 7;

int m_add(int a, int b) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

int m_mul(int a, int b) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

int m_sub(int a, int b) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

int binpow(int x, int y) {
    if (y == 0) {
        return 1;
    }
    int pa = binpow(x, y / 2);
    pa = m_mul(pa, pa);
    if (y % 2 == 1) {
        return m_mul(pa, x);
    }
    return pa;
}

void sol()
{
   int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum = m_add(sum, v[i]);
        }
        
        int ans = 0;

        for (int i = 0; i < n; i++) 
            ans = m_add(ans, m_mul(m_sub(sum, v[i]), v[i]));
        

        cout << m_mul(ans, binpow(m_mul(n, n - 1),m-2)) << endl;
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