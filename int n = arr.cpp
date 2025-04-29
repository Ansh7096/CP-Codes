 int n = arr.size();
    vector<int> px(n + 1, 0);

   
    for (int i = 0; i < n; ++i) {
        px[i + 1] = px[i] ^ arr[i];
    }

    int ans = 0;

   
    for (int m = 0; m <= 1024; m++) {
        unordered_map<int, int> mp;

        
        for (int right = 0; right < n; right++) {
         
            int z = px[right + 1] ^ m;

           
            if (z == val) {
                ans++;
            }

            
            mp[z]++;
        }
    }

    return ans;