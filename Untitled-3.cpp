#include <bits/stdc++.h>

using namespace std;

// Complete the 'getMaximumXORFrequency' function below.
// The function is expected to return an INTEGER.
// The function accepts the following parameters:
//  1. INTEGER_ARRAY arr
//  2. INTEGER val



int getMaximumXORFrequency(vector<int>& arr, int val) {
    int n = arr.size();
    int ans = 0;
    int z = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        z ^= arr[i];
        if (mp.find(z ^ val) != mp.end())
            ans = max(ans, mp[z ^ val] + 1);
        
        if (mp.find(z) != mp.end())
            mp[z] = max(mp[z], i - 1);
        
        else
            mp[z] = i;
        
    }
    return ans;
}

int main() {
    int n, val;
   
    cin >> n;

    vector<int> arr(n);
   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    cin >> val;

    int result = getMaximumXORFrequency(arr, val);
    cout << result << endl;

    return 0;
}


