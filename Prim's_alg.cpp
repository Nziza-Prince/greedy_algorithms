#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void PrimMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1), key(V, INT_MAX);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        inMST[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Prim's MST Edges:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
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
    PrimMST(graph, 6);
    return 0;
}