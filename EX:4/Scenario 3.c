#include <stdio.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}
void reverse_string(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        push(str[i]);
        i++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
}
int main() {
    const char* str = "Hello World!";
    reverse_string(str);
    return 0;
}
