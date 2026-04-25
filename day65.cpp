#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect cycle
bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            // Cycle detected
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    bool hasCycle = false;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}