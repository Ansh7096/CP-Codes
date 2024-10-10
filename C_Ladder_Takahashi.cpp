// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
map<int,vector<int>>adj; 
map<int,int>vis;
int maxi=1;

int dfs(int cur){
    // cout << cur << endl;
    vis[cur]=1;
    maxi=((maxi>cur)?maxi:cur);
    if(adj[cur].size()==0) return cur;
    for(auto it:adj[cur]){
        if(vis[it]==1) continue;
       dfs(it);
    }
    return maxi;
}

void sol()
{
   int n;
   cin>>n; 
   for(int i=0;i<n;i++)
   {
    int x,y;
    cin>>x>>y;
    // if(x>y) swap(x,y);
    adj[x].push_back(y);
    adj[y].push_back(x);
   }
   int maxi=1;
   vis[1]=1;
   maxi=((maxi>dfs(1))?maxi:dfs(1));
   cout << maxi << endl;
   }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin>>t;
    while (t--)
    {
        sol();
    }
}