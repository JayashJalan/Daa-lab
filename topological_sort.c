#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 100
int stack[MAX_NODES], top = -1;
void topologicalSortDFS(int node, int n, int matrix[MAX_NODES][MAX_NODES], bool visited[MAX_NODES]) {
    visited[node] = true;
    for (int c = 0; c < n; c++) {
        if (matrix[node][c] == 1 && !visited[c]) {
            topologicalSortDFS(c, n, matrix, visited);
        }
    }
    stack[++top] = node;
}
void topologicalSort(int n, int matrix[MAX_NODES][MAX_NODES]) {
    bool visited[MAX_NODES] = {false};
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, n, matrix, visited);
        }
    }
    printf("Topological Sort Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int matrix[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix (0 or 1) for a DAG:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    topologicalSort(n, matrix);
    return 0;
}
