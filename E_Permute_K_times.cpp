#include <iostream>
#include <vector>
using namespace std;

void applyPermutation(const vector<int>& X, vector<int>& A) {
    vector<int> B(A.size());
    for (int i = 0; i < X.size(); i++) 
        B[i] = A[X[i] - 1]; 
    
    A = B;
}

int findans(const vector<int>& X) {
    int N = X.size();
    vector<bool> visited(N, false);
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int z = 0;
            int pos = i;
            while (!visited[pos]) {
                visited[pos] = true;
                pos = X[pos] - 1;
                z++;
            }
        ans = max(ans, z);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    unsigned long long K;
    cin >> N >> K;
    
    vector<int> X(N);
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int period = findans(X);
    K %= period;
    
    for (unsigned long long i = 0; i < K; i++) {
        applyPermutation(X, A);
    }
    
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
