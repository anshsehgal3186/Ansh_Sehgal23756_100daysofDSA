#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n]; // (neighbor, weight)

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }

    int source;
    cin >> source;

    vector<int> dist(n, 1e9);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second;

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (d + weight < dist[neighbor]) {
                dist[neighbor] = d + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }

    return 0;
}