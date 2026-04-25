#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> adj[n];

    // Input adjacency list
    // For simplicity, take number of edges also
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s;
    cin >> s;

    vector<bool> visited(n, false);

    dfs(s, adj, visited);

    return 0;
}