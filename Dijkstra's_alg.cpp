#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printPath(vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void Dijkstra(vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1); // to reconstruct the path

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nDijkstra's Shortest Paths from " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (i == src) continue;
        cout << "Shortest path from " << src << " to " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "No path\n";
        } else {
            printPath(parent, i);
            cout << " with cost " << dist[i] << "\n";
        }
    }
}


int main() {
    vector<vector<int>> graph = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    Dijkstra(graph, 1, 6); // From node 1, with 9 nodes
    return 0;
}
