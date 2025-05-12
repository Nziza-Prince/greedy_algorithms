#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Dijkstra(vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Dijkstra's Shortest Paths from " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << src << " -> " << i << " : " << dist[i] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0,2,3,0,0,0},
        {2,0,4,0,5,0},
        {3,4,0,6,0,0},
        {0,0,6,0,5,1},
        {0,5,0,5,0,2},
        {0,0,0,1,2,0}
    };
    Dijkstra(graph, 0, 6);
    return 0;
}