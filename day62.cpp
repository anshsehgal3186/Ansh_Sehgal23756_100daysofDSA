#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Assuming 0-based indexing
        adj[u].push_back(v);

        // Uncomment for undirected graph
        adj[v].push_back(u);
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}