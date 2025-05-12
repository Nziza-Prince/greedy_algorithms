#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int src, dest, weight; };

void KruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    vector<Edge> mst;
    for (Edge e : edges) {
        int x = parent[e.src], y = parent[e.dest];
        if (x != y) {
            mst.push_back(e);
            for (int i = 0; i < V; i++)
                if (parent[i] == y) parent[i] = x;
        }
    }

    cout << "Kruskal's MST Edges:\n";
    for (Edge e : mst)
        cout << e.src << " - " << e.dest << " : " << e.weight << "\n";
}

int main() {
    vector<Edge> edges = {
        {0,1,2}, {0,2,3}, {1,2,4}, {1,4,5},
        {2,3,6}, {3,4,5}, {3,5,1}, {4,5,2}
    };
    KruskalMST(edges, 6);
    return 0;
}