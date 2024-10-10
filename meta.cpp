// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MOD = 998244353;

void sol()
{
    int w, g, l;
    cin >> w >> g >>l;
    int ans;
    if (l > 0)
    {
        int z1 = (w - g) % MOD;
        int z2 = ((2 * (l % MOD)) + 1) % MOD;
        ans = (z1 * z2) % MOD;
    }
    else
        ans = (w - g) % MOD;
    
    cout << ans << endl;
}

void main_()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        sol();
    }
}

static void run_with_stack_size(void (*func)(void), size_t stsize)
{
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
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
    free(stack);
}

signed main()
{
    run_with_stack_size(main_, 1024 * 1024 * 1024);
    return 0;
}
