#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS function
void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    // Push after visiting all neighbors
    st.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    // Input edges (directed)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // u → v
    }

    vector<bool> visited(n, false);
    stack<int> st;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Print topological order
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}