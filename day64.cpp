#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function
void bfs(int s, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> adj[n];

    int m;
    cin >> m;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s;
    cin >> s;

    bfs(s, adj, n);

    return 0;
}