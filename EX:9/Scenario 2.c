#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
#define INF 999999
typedef struct Node {
    int x, y, g, h, f;
    struct Node* parent;
} Node;
int grid[MAX][MAX] = {0}; 
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
void find_path(Node* start, Node* goal) {
    Node* openList[MAX * MAX];
    int openCount = 0;
    start->g = 0;
    start->h = heuristic(start->x, start->y, goal->x, goal->y);
    start->f = start->g + start->h;
    openList[openCount++] = start;
    while (openCount > 0) {
        Node* current = openList[0]; 
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < current->f) current = openList[i];
        }
        if (current->x == goal->x && current->y == goal->y) {
            Node* temp = current;
            while (temp) {
                printf("(%d, %d) <- ", temp->x, temp->y);
                temp = temp->parent;
            }
            return;
        }
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int nx = current->x + dx, ny = current->y + dy;
                if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && grid[nx][ny] == 0) {
                    Node* neighbor = (Node*)malloc(sizeof(Node));
                    neighbor->x = nx; neighbor->y = ny;
                    neighbor->g = current->g + 1;
                    neighbor->h = heuristic(nx, ny, goal->x, goal->y);
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;
                    openList[openCount++] = neighbor;
                }
            }
        }
    }
}
int main() {
    Node start = {0, 0}, goal = {4, 4};
    grid[1][1] = 1; grid[2][2] = 1; grid[3][3] = 1;
    find_path(&start, &goal);
    return 0;
}
