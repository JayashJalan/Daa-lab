#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 100
int node_steps = 0, edge_steps = 0;
void dfs(int node, int n, int matrix[MAX_NODES][MAX_NODES], bool v[MAX_NODES]) {
    v[node] = true;
    printf("%d ", node);
    node_steps++;
    for (int c = 0; c < n; c++) {
        edge_steps++;
        if (matrix[node][c] == 1 && !v[c]) {
            dfs(c, n, matrix, v);
        }
    }
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int matrix[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int x;
    printf("Enter the starting node for DFS (0 to %d): ", n - 1);
    scanf("%d", &x);
    bool v[MAX_NODES] = {false};
    printf("DFS starting from node %d: ", x);
    dfs(x, n, matrix, v);
    int total_steps = node_steps + edge_steps;
    printf("\n\nBFS Steps Analysis:");
    printf("\nNodes processed: %d", node_steps);
    printf("\nEdge examinations: %d", edge_steps);
    printf("\nTotal steps: %d\n", total_steps);
    return 0;
}
