#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], n, indegree[MAX];
int main() {
    int i, j, v;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%d", &adj[i][j]) != 1) return 1;
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++)
            if (adj[j][i]) indegree[i]++;
    }
    int q[MAX], f = 0, r = 0, count = 0, order[MAX];
    for (i = 0; i < n; i++) if (indegree[i] == 0) q[r++] = i;
    while (f < r) {
        int u = q[f++];
        order[count++] = u;
        for (v = 0; v < n; v++)
            if (adj[u][v] && --indegree[v] == 0) q[r++] = v;
    }
    if (count < n) printf("The graph has a cycle, topological ordering is not possible.\n");
    else {
        printf("Topological Ordering is: ");
        for (i = 0; i < count; i++) printf("%d ", order[i]);
        printf("\n");
    }
    return 0;
}
