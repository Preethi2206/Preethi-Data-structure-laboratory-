#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITLE_LENGTH 100
typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    struct Book* next;
    struct Book* prev;
} Book;
Book* head = NULL;
Book* tail = NULL;
void add_book(const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->next = NULL;
    newBook->prev = tail;
    if (tail) {
        tail->next = newBook;
    } else {
        head = newBook;  
    }
    tail = newBook;
}
void remove_book(const char* title) {
    Book* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}
void display_books_forward() {
    Book* temp = head;
    while (temp) {
        printf("%s\n", temp->title);
        temp = temp->next;
    }
}
void display_books_reverse() {
    Book* temp = tail;
    while (temp) {
        printf("%s\n", temp->title);
        temp = temp->prev;
    }
}
int main() {
    add_book("Book 1");
    add_book("Book 2");
    add_book("Book 3");
    printf("Books (Forward):\n");
    display_books_forward();
    remove_book("Book 2");
    printf("\nBooks (Forward) after removal:\n");
    display_books_forward();
    printf("\nBooks (Reverse):\n");
    display_books_reverse();
    return 0;
}
