#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}
int pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}
int evaluate_postfix(const char* expr) {
    int i = 0, num1, num2, result;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            num2 = pop();
            num1 = pop();
            switch (expr[i]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
            }
            push(result);
        }
        i++;
    }
    return pop();
}
int main() {
    const char* expr = "23 45 + 6 *";
    int result = evaluate_postfix(expr);
    printf("Result: %d\n", result);
    return 0;
}
