#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_LOCATIONS 10
typedef struct Graph {
    int adjMatrix[MAX_LOCATIONS][MAX_LOCATIONS];
    int numLocations;
} Graph;
void init_graph(Graph* g, int numLocations) {
    g->numLocations = numLocations;
    for (int i = 0; i < numLocations; i++) {
        for (int j = 0; j < numLocations; j++) {
            g->adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}
void add_route(Graph* g, int from, int to, int distance) {
    g->adjMatrix[from][to] = distance;
    g->adjMatrix[to][from] = distance;
}
int min_distance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(Graph* g, int start) {
    int dist[MAX_LOCATIONS];
    int visited[MAX_LOCATIONS] = {0};
    for (int i = 0; i < g->numLocations; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    for (int i = 0; i < g->numLocations - 1; i++) {
        int u = min_distance(dist, visited, g->numLocations);
        visited[u] = 1;
        for (int v = 0; v < g->numLocations; v++) {
            if (!visited[v] && g->adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + g->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjMatrix[u][v];
            }
        }
    }
    for (int i = 0; i < g->numLocations; i++) {
        printf("Distance from %d to %d is %d\n", start, i, dist[i]);
    }
}
int main() {
    Graph g;
    init_graph(&g, 5);
    add_route(&g, 0, 1, 10);
    add_route(&g, 0, 2, 5);
    add_route(&g, 1, 2, 2);
    add_route(&g, 1, 3, 1);
    add_route(&g, 2, 3, 9);
    add_route(&g, 3, 4, 4);
    dijkstra(&g, 0);
    return 0;
}
