#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct Edge {
    int u, v, weight;
} Edge;
Edge edges[MAX];
int parent[MAX], rank[MAX];
int find(int i) {
    if (parent[i] == -1) return i;
    return parent[i] = find(parent[i]);
}
void union_sets(int u, int v) {
    int root_u = find(u), root_v = find(v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) parent[root_v] = root_u;
        else if (rank[root_u] < rank[root_v]) parent[root_u] = root_v;
        else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}
int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}
void kruskal(int n, int m) {
    qsort(edges, m, sizeof(Edge), compare);
    for (int i = 0; i < n; i++) parent[i] = -1, rank[i] = 0;  
    int mst_cost = 0, count = 0;
    for (int i = 0; i < m && count < n-1; i++) {
        int u = edges[i].u, v = edges[i].v, weight = edges[i].weight;
        if (find(u) != find(v)) {
            union_sets(u, v);
            mst_cost += weight;
            count++;
        }
    }
    printf("Minimum construction cost: %d\n", mst_cost);
}
int main() {
    int n = 4, m = 5;
    edges[0] = (Edge){0, 1, 10};
    edges[1] = (Edge){0, 2, 6};
    edges[2] = (Edge){0, 3, 5};
    edges[3] = (Edge){1, 3, 15};
    edges[4] = (Edge){2, 3, 4};
    kruskal(n, m);
    return 0;
}
