#include <stdio.h>
#include <string.h>
#define MAX_HISTORY 100
#define MAX_URL_LENGTH 100
char history[MAX_HISTORY][MAX_URL_LENGTH];
int top = -1;
void push_url(const char* url) {
    if (top < MAX_HISTORY - 1) {
        strcpy(history[++top], url);
    } else {
        printf("History is full.\n");
    }
}
void pop_url() {
    if (top >= 0) {
        printf("Removed: %s\n", history[top--]);
    } else {
        printf("No history to remove.\n");
    }
}
void display_history() {
    if (top == -1) {
        printf("No browsing history.\n");
        return;
    }
    printf("Browsing History:\n");
    for (int i = 0; i <= top; i++) {
        printf("%s\n", history[i]);
    }
}
int main() {
    push_url("https://example.com");
    push_url("https://openai.com");
    push_url("https://github.com");
    display_history();
    pop_url();
    printf("\nUpdated History:\n");
    display_history();
    return 0;
}
