#include <stdio.h>
#include <stdlib.h>
struct Edge { int src, dest, weight; };
struct subset { int parent, rank; };
int find(struct subset s[], int i) {
    if (s[i].parent != i) s[i].parent = find(s, s[i].parent);
    return s[i].parent;
}
void Union(struct subset s[], int x, int y) {
    int xr = find(s, x), yr = find(s, y);
    if (s[xr].rank < s[yr].rank) s[xr].parent = yr;
    else if (s[xr].rank > s[yr].rank) s[yr].parent = xr;
    else { s[yr].parent = xr; s[xr].rank++; }
}
int comp(const void* a, const void* b) {
    return ((struct Edge*)a)->weight > ((struct Edge*)b)->weight;
}
int main() {
    int V = 5, E = 7, e = 0, i = 0;
    struct Edge edge[7] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };
    struct Edge res[5];
    qsort(edge, E, sizeof(struct Edge), comp);
    struct subset s[5];
    for (int v = 0; v < V; v++) { s[v].parent = v; s[v].rank = 0; }
    while (e < V - 1 && i < E) {
        struct Edge next = edge[i++];
        int x = find(s, next.src), y = find(s, next.dest);
        if (x != y) { res[e++] = next; Union(s, x, y); }
    }
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d \n", res[i].src, res[i].dest, res[i].weight);
    return 0;
}
