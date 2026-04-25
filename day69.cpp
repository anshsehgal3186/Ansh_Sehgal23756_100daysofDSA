#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    vector<int> dist(n, 1e9);
    dist[source] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] != 1e9 && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative cycle
    for (auto e : edges) {
        if (dist[e.u] != 1e9 && dist[e.u] + e.w < dist[e.v]) {
            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }

    // Print distances
    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }

    return 0;
}