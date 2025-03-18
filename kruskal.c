#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    int parent, rank;
} Subset;
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
void kruskalMST(Edge edges[], int V, int E) {
    Edge result[MAX];
    Subset subsets[MAX];
    qsort(edges, E, sizeof(Edge), compareEdges);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int mstSize = 0, edgeCount = 0;
    while (mstSize < V - 1 && edgeCount < E) {
        Edge nextEdge = edges[edgeCount++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result[mstSize++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    printf("\nEdge \tWeight\n");
    for (int i = 0; i < mstSize; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}
int main() {
    int V, graph[MAX][MAX], edgeCount = 0;
    Edge edges[MAX * MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] != 0 && i < j) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
    kruskalMST(edges, V, edgeCount);
    return 0;
}
