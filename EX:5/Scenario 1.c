#include <stdio.h>
#include <stdlib.h>
typedef struct Book {
    int isbn;
    char title[100];
    struct Book* left;
    struct Book* right;
} Book;
Book* root = NULL;
Book* create_book(int isbn, const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->isbn = isbn;
    strcpy(newBook->title, title);
    newBook->left = newBook->right = NULL;
    return newBook;
}
Book* insert(Book* node, int isbn, const char* title) {
    if (node == NULL) return create_book(isbn, title);
    if (isbn < node->isbn) node->left = insert(node->left, isbn, title);
    else if (isbn > node->isbn) node->right = insert(node->right, isbn, title);
    return node;
}
Book* search(Book* root, int isbn) {
    if (root == NULL || root->isbn == isbn) return root;
    if (isbn < root->isbn) return search(root->left, isbn);
    return search(root->right, isbn);
}
void inorder(Book* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("ISBN: %d, Title: %s\n", root->isbn, root->title);
        inorder(root->right);
    }
}
int main() {
    root = insert(root, 12345, "Book A");
    insert(root, 67890, "Book B");
    insert(root, 11223, "Book C");
    printf("Book Inventory:\n");
    inorder(root);
    int searchIsbn = 67890;
    Book* book = search(root, searchIsbn);
    if (book != NULL) {
        printf("\nFound Book: ISBN: %d, Title: %s\n", book->isbn, book->title);
    } else {
        printf("\nBook not found.\n");
    }
    return 0;
}
