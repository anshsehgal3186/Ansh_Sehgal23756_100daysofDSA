#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (weight, node)

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    // Input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start from node 1
    pq.push({0, 1});

    int mstWeight = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int weight = top.first;
        int node = top.second;

        if (visited[node]) continue;

        visited[node] = true;
        mstWeight += weight;

        for (auto neighbor : adj[node]) {
            int next = neighbor.first;
            int w = neighbor.second;

            if (!visited[next]) {
                pq.push({w, next});
            }
        }
    }

    cout << mstWeight;

    return 0;
}
