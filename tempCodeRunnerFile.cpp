#include <bits/stdc++.h>
using namespace std;

int countSwaps(vector<int>& arrA, vector<int>& arrb) {
    map<int, int> mp1, mp2;
    set<int> s;
    
    // Count frequencies in arrA and insert into set
    for (auto it : arrA) {
        mp1[it]++;
        s.insert(it);
    }
    
    // Count frequencies in arrb and insert into set
    for (auto it : arrb) {
        mp2[it]++;
        s.insert(it);
    }
    
    int ans = 0;
    
    // Iterate through the set of unique elements
    for (auto it : s) {
        ans += abs(mp1[it] - mp2[it]) / 2;  // Count difference in half (as per problem statement)
    }
    
    return ans;
}

int main() {
    vector<int> arrA = {1, 2};
    vector<int> arrb = {2, 1};
    
    int result = countSwaps(arrA, arrb);
    cout << "Minimum number of swaps or adjustments needed: " << result << endl;
    
    return 0;
}
