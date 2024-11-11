#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void add_customer(int customer_id) {
    if (rear < MAX - 1) {
        if (front == -1) front = 0;
        queue[++rear] = customer_id;
    } else {
        printf("Queue is full.\n");
    }
}
void serve_customer() {
    if (front == -1 || front > rear) {
        printf("No customers to serve.\n");
    } else {
        printf("Serving customer: %d\n", queue[front++]);
    }
}
void display_queue() {
    if (front == -1 || front > rear) {
        printf("No customers in queue.\n");
    } else {
        printf("Customers in queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("Customer %d\n", queue[i]);
        }
    }
}
int main() {
    add_customer(1);
    add_customer(2);
    add_customer(3);
    display_queue();
    serve_customer();
    printf("\nAfter serving one customer:\n");
    display_queue();
    return 0;
}
