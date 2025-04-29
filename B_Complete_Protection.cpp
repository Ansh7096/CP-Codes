#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> ids, low;
vector<bool> onStack;
stack<int> s;
int id = 0, sccCount = 0;

void tarjanDFS(int at, vector<int>& sccSizes) {
    ids[at] = low[at] = id++;
    s.push(at);
    onStack[at] = true;

    for (int to : adj[at]) {
        if (ids[to] == -1) {
            tarjanDFS(to, sccSizes);
            low[at] = min(low[at], low[to]);
        } else if (onStack[to]) {
            low[at] = min(low[at], ids[to]);
        }
    }

    // On root node, pop the stack and generate an SCC
    if (ids[at] == low[at]) {
        int node;
        int sccSize = 0;
        do {
            node = s.top();
            s.pop();
            onStack[node] = false;
            low[node] = ids[at]; // Assign the root id to each SCC node
            sccSize++;
        } while (node != at);

        sccSizes.push_back(sccSize);
        sccCount++;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    ids.assign(N + 1, -1);
    low.resize(N + 1);
    onStack.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[B].push_back(A);
    }

    vector<int> sccSizes;
    for (int i = 1; i <= N; i++) {
        if (ids[i] == -1) {
            tarjanDFS(i, sccSizes);
        }
    }

    // Check if any SCC has more than one node
    for (int size : sccSizes) {
        if (size > 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
