// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    unordered_map<int, int> f;
    int maxCount = 0, mostFrequent = v[0];

    for (int num : v) {
        f[num]++;
        if (f[num] > maxCount) {
            maxCount = f[num];
            mostFrequent = num;
        }
    }
    int ans=0;
    for(int num:v)
    {
        if(num==mostFrequent)
        continue;
        else 
        ans++;
    }
    cout<<ans<<endl;
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