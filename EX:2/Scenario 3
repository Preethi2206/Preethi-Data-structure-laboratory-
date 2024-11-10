#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    if (top < MAX - 1) stack[++top] = ch;
}
char pop() {
    return (top >= 0) ? stack[top--] : '\0';
}
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}
void infix_to_postfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    while (infix[i]) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') postfix[j++] = pop();
            pop();
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }
    while (top >= 0) postfix[j++] = pop();
    postfix[j] = '\0';
}
int main() {
    char infix[MAX] = "3+5*2/(7-2)";
    char postfix[MAX];
    infix_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
