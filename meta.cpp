#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
const int mod = 998244353;

void sl() {
    int r, c;
    int k;
    cin >> r >> c >> k;

    vector<vector<int>> g(r, vector<int>(c));
    int mxid = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> g[i][j];
            if(g[i][j] > mxid) mxid = g[i][j];
        }
    }

    vector<vector<pair<int, int>>> bncells(mxid + 1);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            bncells[g[i][j]].emplace_back(i, j);
        }
    }

    int l = 0, rt = max(r, c);
    int ans = max(r, c);

    while(l <= rt) {
        int mid = l + (rt - l) / 2;
        int sr = min(mid, r - 1);
        int sc = min(mid, c - 1);

        int sumr = (int)r * (2LL * sr + 1) - 1LL * sr * (sr + 1);
        int sumc = (int)c * (2LL * sc + 1) - 1LL * sc * (sc + 1);
        int tps = sumr * sumc - (int)r * c; 
        int z = 0; 

        for(int b = 1; b <= mxid; b++) {
            int l = bncells[b].size();
            if(l <= 1) continue;

            vector<pair<int, int>> &cells = bncells[b];
            sort(cells.begin(), cells.end());

            for(int r = 0; r < l; r++) {
                int z1 = cells[r].first;
                int z2 = cells[r].second;
                
                int lb = lower_bound(cells.begin(), cells.end(), make_pair(z1 - mid, -1)) - cells.begin();
                int ub = upper_bound(cells.begin(), cells.end(), make_pair(z1 + mid, c)) - cells.begin();
                
               

                int lwidx = lower_bound(cells.begin() + lb, cells.begin() + ub, make_pair(0, z1-mid),
                    [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
                        return a.second < b.second;
                    }) - cells.begin();

                int upidx = upper_bound(cells.begin() + lb, cells.begin() + ub, make_pair(0, z1+mid),
                    [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
                        return a.second < b.second;
                    }) - cells.begin();

                z += (int)(upidx - lwidx);
            }
            z -= (int)l;
        }

       
        if(tps-z >= k) {
            ans = mid;
            rt = mid - 1;
        } else 
            l = mid + 1;
        
    }

    cout << ans << endl;
}

void main_() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        sl();
    }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stk, *send;
    stk = (char *)malloc(stsize);
    send = stk + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%esp\n"
                 :
                 : "r"(send));
    free(stk);
}

signed main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024);
    return 0;
}
