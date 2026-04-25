#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    // Input edges (undirected graph)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, 1e9);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second;

        // Skip outdated entries
        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print distances (1 to n)
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}