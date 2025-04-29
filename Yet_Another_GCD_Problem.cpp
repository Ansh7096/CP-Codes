#include <bits/stdc++.h>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to count co-prime pairs in an array
int countCoPrimePairs(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(arr[i], arr[j]) == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to generate array with required co-prime pairs
vector<int> generateArray(int n, int k) {
    // Special cases
    if (n == 1 || k > (n * (n - 1)) / 2) return {-1};
    
    // For n == 2, we can only have 0 or 1 co-prime pair
    if (n == 2) {
        if (k == 1) return {2, 3};  // Co-prime numbers
        if (k == 0) return {2, 4};  // Non co-prime numbers
        return {-1};
    }
    
    // For larger n, we'll use a combination of co-prime and non co-prime numbers
    vector<int> result;
    
    // Strategy:
    // 1. Use small prime numbers when we need more co-prime pairs
    // 2. Use multiples of a number when we need fewer co-prime pairs
    
    int maxPossiblePairs = (n * (n - 1)) / 2;
    if (k > maxPossiblePairs) return {-1};
    
    if (k == maxPossiblePairs) {
        // Need all pairs to be co-prime
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = 0; i < n; i++) {
            result.push_back(primes[i % primes.size()]);
        }
    } else {
        // Mix of co-prime and non co-prime numbers
        result.push_back(2);  // First number
        
        int remainingPairs = k;
        int currentPos = 1;
        
        while (currentPos < n) {
            int pairsNeeded = min(remainingPairs, n - currentPos);
            
            if (pairsNeeded > 0) {
                // Add a prime number to create co-prime pairs
                result.push_back(result.back() + 1);
                remainingPairs--;
            } else {
                // Add a multiple of the first number to avoid co-prime pairs
                result.push_back(result[0] * (currentPos + 1));
            }
            currentPos++;
        }
    }
    
    // Verify the solution
    if (countCoPrimePairs(result) != k) return {-1};
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> result = generateArray(n, k);
        
        if (result[0] == -1) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << (i < result.size() - 1 ? " " : "\n");
            }
        }
    }
    
    return 0;
}