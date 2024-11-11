#include <stdio.h>
#include <stdlib.h>
typedef struct Inquiry {
    int inquiry_id;
    struct Inquiry* next;
} Inquiry;
Inquiry* front = NULL;
Inquiry* rear = NULL;
void add_inquiry(int inquiry_id) {
    Inquiry* newInquiry = (Inquiry*)malloc(sizeof(Inquiry));
    newInquiry->inquiry_id = inquiry_id;
    newInquiry->next = NULL;
    if (rear) {
        rear->next = newInquiry;
    } else {
        front = newInquiry;
    }
    rear = newInquiry;
}
void resolve_inquiry() {
    if (!front) {
        printf("No inquiries to resolve.\n");
    } else {
        Inquiry* temp = front;
        printf("Resolving inquiry: %d\n", front->inquiry_id);
        front = front->next;
        if (!front) rear = NULL;
        free(temp);
    }
}
void display_inquiries() {
    if (!front) {
        printf("No inquiries in queue.\n");
    } else {
        Inquiry* temp = front;
        printf("Current inquiries in queue:\n");
        while (temp) {
            printf("Inquiry %d\n", temp->inquiry_id);
            temp = temp->next;
        }
    }
}
int main() {
    add_inquiry(101);
    add_inquiry(102);
    add_inquiry(103);
    display_inquiries();
    resolve_inquiry();
    printf("\nAfter resolving one inquiry:\n");
    display_inquiries();
    return 0;
}
