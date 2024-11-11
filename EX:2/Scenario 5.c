#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char data;
    struct Node* next;
} Node;
Node* top = NULL;
void push(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}
void pop() {
    if (top) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}
int is_balanced(const char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (!top) return 0;
            if ((expr[i] == ')' && top->data != '(') ||
                (expr[i] == '}' && top->data != '{') ||
                (expr[i] == ']' && top->data != '[')) {
                return 0;
            }
            pop();
        }
    }
    return top == NULL;
}
int main() {
    const char* expr = "{[()]}";
    if (is_balanced(expr)) printf("Balanced\n");
    else printf("Not Balanced\n");
    return 0;
}
