#include <stdio.h>
#include <stdlib.h>
typedef struct Customer {
    int customer_id;
    struct Customer* next;
} Customer;
Customer* front = NULL;
Customer* rear = NULL;
void enqueue_customer(int customer_id) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->customer_id = customer_id;
    newCustomer->next = NULL;
    if (rear) {
        rear->next = newCustomer;
    } else {
        front = newCustomer;
    }
    rear = newCustomer;
}
void dequeue_customer() {
    if (!front) {
        printf("No customers in the queue.\n");
    } else {
        Customer* temp = front;
        printf("Serving customer: %d\n", front->customer_id);
        front = front->next;
        if (!front) rear = NULL;
        free(temp);
    }
}
void display_queue() {
    if (!front) {
        printf("No customers in the queue.\n");
    } else {
        Customer* temp = front;
        printf("Customers in queue:\n");
        while (temp) {
            printf("Customer %d\n", temp->customer_id);
            temp = temp->next;
        }
    }
}
int main() {
    enqueue_customer(101);
    enqueue_customer(102);
    enqueue_customer(103);
    display_queue();
    dequeue_customer();
    printf("\nAfter serving one customer:\n");
    display_queue();
    return 0;
}
