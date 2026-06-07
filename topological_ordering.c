#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int n;
int indegree[MAX];

void calculateIndegree() {
    int i, j;
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }
}

int main() {
    int i, j, v;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) return 1;
        }
    }

    calculateIndegree();

    int queue[MAX];
    int front = 0, rear = 0;

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topo_order[MAX];

    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count < n) {
        printf("The graph has a cycle, topological ordering is not possible.\n");
    } else {
        printf("Topological Ordering is: ");
        for (i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }

    return 0;
}
