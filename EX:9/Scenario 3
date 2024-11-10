#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10
int graph[MAX][MAX] = {{0}};
int dist[MAX], prev[MAX], visited[MAX];
void dijkstra(int src, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        prev[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int minDist = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}
void print_path(int dest) {
    if (prev[dest] == -1) return;
    print_path(prev[dest]);
    printf("%d -> ", dest);
}
int main() {
    int n = 5;
    graph[0][1] = 10; graph[1][2] = 20; graph[2][3] = 30;
    graph[3][4] = 40; graph[0][4] = 100;
    dijkstra(0, n);
    printf("Shortest path to 4: ");
    print_path(4);
    printf("Cost: %d\n", dist[4]);
    return 0;
}
