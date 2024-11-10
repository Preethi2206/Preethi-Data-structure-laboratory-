#include <stdio.h>
#include <string.h>
#define MAX_CHANGES 100
#define MAX_CHANGE_LENGTH 100
char changes[MAX_CHANGES][MAX_CHANGE_LENGTH];
int top = -1;
void push_change(const char* change) {
    if (top < MAX_CHANGES - 1) {
        strcpy(changes[++top], change);
    } else {
        printf("Undo stack is full.\n");
    }
}
void pop_change() {
    if (top >= 0) {
        printf("Undo: %s\n", changes[top--]);
    } else {
        printf("No changes to undo.\n");
    }
}
void display_changes() {
    if (top == -1) {
        printf("No changes made.\n");
        return;
    }
    printf("Changes made:\n");
    for (int i = 0; i <= top; i++) {
        printf("%s\n", changes[i]);
    }
}
int main() {
    push_change("Added line 1");
    push_change("Added line 2");
    push_change("Deleted line 1");
    display_changes();
    pop_change();
    printf("\nAfter undo:\n");
    display_changes();
    return 0;
}
