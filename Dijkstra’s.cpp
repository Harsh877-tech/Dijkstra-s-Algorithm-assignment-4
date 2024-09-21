#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    // Step 1: Visualize the graph
    void printGraph() {
        cout << "Graph Visualization:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (const auto& [v, weight] : adj[i]) {
                cout << "(" << v << "," << weight << ") ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    // Dijkstra's Algorithm implementation
    pair<vector<int>, int> dijkstra(int start, int end) {
        vector<int> dist(V, INF);
        vector<int> prev(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (u == end) break;

            if (d > dist[u]) continue;

            for (const auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        // Reconstruct path
        vector<int> path;
        for (int v = end; v != -1; v = prev[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        return {path, dist[end]};
    }
};

int main() {
    // Step 3: Hard-code the graph data as per the assignment
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 2, 7);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 2, 8);
    g.addEdge(4, 3, 2);

    // Step 1: Visualize the graph
    g.printGraph();

    // Step 2:  asking User input and algorithm execution
    int start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    auto [path, cost] = g.dijkstra(start, end);

    // Output results
    cout << "Shortest path from " << start << " to " << end << ": ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\nCost of the shortest path: " << cost << endl;

    return 0;
}
