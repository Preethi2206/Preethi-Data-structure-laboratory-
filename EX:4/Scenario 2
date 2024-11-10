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
int is_balanced(const char* code) {
    int i = 0;
    char c;
    while ((c = code[i]) != '\0') {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char top_char = pop();
            if ((c == ')' && top_char != '(') ||
                (c == '}' && top_char != '{') ||
                (c == ']' && top_char != '[')) {
                return 0;
            }
        }
        i++;
    }
    return top == -1;
}
int main() {
    const char* code = "if (x > 0) { return (x); }";
    if (is_balanced(code)) {
        printf("Syntax is correct.\n");
    } else {
        printf("Syntax error: unmatched closing bracket.\n");
    }
    return 0;
}
