#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue_call(int call_id) {
    if (rear < MAX - 1) {
        if (front == -1) front = 0;
        queue[++rear] = call_id;
    } else {
        printf("Queue is full.\n");
    }
}
void dequeue_call() {
    if (front == -1 || front > rear) {
        printf("No calls to attend.\n");
    } else {
        printf("Attending call: %d\n", queue[front++]);
    }
}
void display_queue() {
    if (front == -1 || front > rear) {
        printf("No calls in queue.\n");
    } else {
        printf("Current calls in queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("Call %d\n", queue[i]);
        }
    }
}
int main() {
    enqueue_call(101);
    enqueue_call(102);
    enqueue_call(103);
    display_queue();
    dequeue_call();
    printf("\nAfter attending one call:\n");
    display_queue();
    return 0;
}
