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
int is_empty() {
    return top == NULL;
}
int check_syntax(const char* code) {
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '(' || code[i] == '{' || code[i] == '[') {
            push(code[i]);
        } else if (code[i] == ')' || code[i] == '}' || code[i] == ']') {
            if (is_empty()) return 0;
            if ((code[i] == ')' && top->data != '(') ||
                (code[i] == '}' && top->data != '{') ||
                (code[i] == ']' && top->data != '[')) {
                return 0;
            }
            pop();
        }
    }
    return is_empty();
}
int main() {
    const char* code = "int main() { return (a + b) * [c - d]; }";
    if (check_syntax(code)) printf("Syntax is correct\n");
    else printf("Syntax error\n");
    return 0;
}
