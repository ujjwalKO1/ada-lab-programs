#include <stdio.h>
#include <stdbool.h>
#define V 5
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool spt[V];
    for (int i = 0; i < V; i++) { dist[i] = 99999; spt[i] = false; }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int min = 99999, u;
        for (int v = 0; v < V; v++)
            if (!spt[v] && dist[v] <= min) { min = dist[v]; u = v; }
        spt[u] = true;
        for (int v = 0; v < V; v++)
            if (!spt[v] && graph[u][v] && dist[u] != 99999 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Vertex \t Distance from Source (0)\n---------------------------------\n");
    for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]);
}
int main() {
    int graph[V][V] = {
        { 0, 10, 0, 5, 0 },
        { 10, 0, 1, 2, 0 },
        { 0, 1, 0, 9, 4 },
        { 5, 2, 9, 0, 2 },
        { 0, 0, 4, 2, 0 }
    };
    dijkstra(graph, 0);
    return 0;
}
