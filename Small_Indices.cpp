#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <utility>

using namespace std;

struct pair_hash {
    template <class t1, class t2>
    size_t operator()(const pair<t1, t2>& p) const {
        auto hash1 = hash<t1>{}(p.first);
        auto hash2 = hash<t2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

vector<int> max_small_indices(int t, const vector<tuple<int, vector<int>, vector<int>>>& vv) {
    vector<int> ans;

    for (int i = 0; i < t; i++) {
        int n = get<0>(vv[i]);
        vector<int> a = get<1>(vv[i]);
        vector<int> b = get<2>(vv[i]);

        int c1 = max(a[0], b[0]);
        int c2 = max(a[1], b[1]);
        if (c1 < c2) swap(c1, c2); 

        unordered_map<pair<int, int>, int, pair_hash> dp;
        dp[{c1, c2}] = 0;

        for (int i = 2; i < n; i++) 
        {
            unordered_map<pair<int, int>, int, pair_hash> dp2;

            for (const auto& entry : dp)
             {
                int mx1 = entry.first.first;
                int mx2 = entry.first.second;
                int co = entry.second;

                for (int ci : {a[i], b[i]}) 
                {
                    int zi = (ci <= mx1 + mx2) ? co + 1 : co;

                    int z1 = mx1, z2 = mx2;
                    if (ci > mx1) 
                    {
                        z2 = mx1;
                        z1 = ci;
                    } else if (ci > mx2) 
                        z2 = ci;
                    

                    if (z1 < z2) swap(z1, z2);

                    pair<int, int> key = {z1, z2};
                    if (dp2.find(key) == dp2.end() || dp2[key] < zi)
                        dp2[key] = zi;
                    
                }
            }

            dp = move(dp2);
        }

        int max_co = 0;
        for (const auto& entry : dp) {
            max_co = max(max_co, entry.second);
        }
        ans.push_back(max_co);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    vector<tuple<int, vector<int>, vector<int>>> vv;

    for (int tt = 0; tt < t; ++tt) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vv.emplace_back(n, a, b);
    }

    vector<int> ans = max_small_indices(t, vv);

    for (int res : ans) 
        cout << res << endl;
    

    return 0;
}
