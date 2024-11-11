#include <stdio.h>
#include <stdlib.h>
typedef struct Student {
    int id;
    char name[100];
    struct Student* left;
    struct Student* right;
} Student;
Student* root = NULL;
Student* create_student(int id, const char* name) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->left = newStudent->right = NULL;
    return newStudent;
}
Student* insert(Student* node, int id, const char* name) {
    if (node == NULL) return create_student(id, name);
    if (id < node->id) node->left = insert(node->left, id, name);
    else if (id > node->id) node->right = insert(node->right, id, name);
    return node;
}
Student* search(Student* root, int id) {
    if (root == NULL || root->id == id) return root;
    if (id < root->id) return search(root->left, id);
    return search(root->right, id);
}
void inorder(Student* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Student ID: %d, Name: %s\n", root->id, root->name);
        inorder(root->right);
    }
}
int main() {
    root = insert(root, 1001, "Alice");
    insert(root, 1003, "Bob");
    insert(root, 1002, "Charlie");
    printf("All Student IDs in Ascending Order:\n");
    inorder(root);
    int searchId = 1002;
    Student* student = search(root, searchId);
    if (student != NULL) {
        printf("\nFound Student: ID: %d, Name: %s\n", student->id, student->name);
    } else {
        printf("\nStudent not found.\n");
    }
    return 0;
}
