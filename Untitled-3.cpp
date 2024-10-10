#include <bits/stdc++.h>
using namespace std;

int mincost(vector<int> &pods,vector<int> &cost){
  map<int,multiset<int>> mp;
  for(int i=0;i<pods.size();i++){
    mp[pods[i]].insert(cost[i]);
  }
  int ans = 0;
  int curr = (*mp.begin()).first,sm = 0;
  multiset<int> se;
  while(1){
    if(se.size()==0){
      if(mp.lower_bound(curr) == mp.end()) break;
      curr = (*mp.lower_bound(curr)).first;
    }

    if(mp.find(curr) != mp.end())
    for(auto &x:mp[curr]){
        se.insert(x);
        sm += x;
    }

    auto it = se.end();
    it--;
    sm -= *it;
    ans += sm;
    se.erase(it);
    curr++;
  }
}
int main() {
   
    vector<int> pods = {5,2,5,3,3};  // pod ids
    vector<int> cost = {3,7,8,6,9}; // associated costs

    // Call mincost function and output result
    cout << "Minimum cost: " << mincost(pods, cost) << endl;

    return 0;
}
