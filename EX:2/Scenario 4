#include <stdio.h>
#include <stdlib.h>
typedef struct Move {
    int position;
    struct Move* next;
} Move;
Move* top = NULL;
void push_move(int position) {
    Move* newMove = (Move*)malloc(sizeof(Move));
    newMove->position = position;
    newMove->next = top;
    top = newMove;
}
void pop_move() {
    if (top) {
        Move* temp = top;
        printf("Undo move at position: %d\n", top->position);
        top = top->next;
        free(temp);
    } else {
        printf("No moves to undo.\n");
    }
}
void display_moves() {
    Move* temp = top;
    if (!temp) {
        printf("No moves made.\n");
        return;
    }
    printf("Moves stack:\n");
    while (temp) {
        printf("%d\n", temp->position);
        temp = temp->next;
    }
}
int main() {
    push_move(1);
    push_move(3);
    push_move(5);
    display_moves();
    pop_move();
    printf("\nAfter undo:\n");
    display_moves();
    return 0;
}
