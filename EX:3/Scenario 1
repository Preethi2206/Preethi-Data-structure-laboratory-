#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int job) {
    if (rear < MAX - 1) {
        if (front == -1) front = 0;
        queue[++rear] = job;
    } else {
        printf("Queue is full.\n");
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Processing job: %d\n", queue[front++]);
    }
}
void display_queue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Current queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("Job %d\n", queue[i]);
        }
    }
}
int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);
    display_queue();
    dequeue();
    printf("\nAfter dequeue:\n");
    display_queue();
    return 0;
}
