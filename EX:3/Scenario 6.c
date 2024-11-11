#include <stdio.h>
#include <stdlib.h>
typedef struct RideRequest {
    int request_id;
    struct RideRequest* next;
} RideRequest;
RideRequest* front = NULL;
RideRequest* rear = NULL;
void add_ride_request(int request_id) {
    RideRequest* newRequest = (RideRequest*)malloc(sizeof(RideRequest));
    newRequest->request_id = request_id;
    newRequest->next = NULL;
    if (rear) {
        rear->next = newRequest;
    } else {
        front = newRequest;
    }
    rear = newRequest;
}
void serve_ride_request() {
    if (!front) {
        printf("No ride requests to serve.\n");
    } else {
        RideRequest* temp = front;
        printf("Serving ride request: %d\n", front->request_id);
        front = front->next;
        if (!front) rear = NULL;
        free(temp);
    }
}
void display_requests() {
    if (!front) {
        printf("No pending ride requests.\n");
    } else {
        RideRequest* temp = front;
        printf("Pending ride requests:\n");
        while (temp) {
            printf("Request %d\n", temp->request_id);
            temp = temp->next;
        }
    }
}
int main() {
    add_ride_request(101);
    add_ride_request(102);
    add_ride_request(103);
    display_requests();
    serve_ride_request();
    printf("\nAfter serving one ride request:\n");
    display_requests();
    return 0;
}
