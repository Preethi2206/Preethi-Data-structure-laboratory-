#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[100];
    int age;
} Student;
Student* search_student(Student* records, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }
    return NULL;
}
int main() {
    int n = 3;
    Student* records = (Student*)malloc(n * sizeof(Student));
    records[0].id = 101;
    strcpy(records[0].name, "Alice");
    records[0].age = 20;
    records[1].id = 102;
    strcpy(records[1].name, "Bob");
    records[1].age = 22;
    records[2].id = 103;
    strcpy(records[2].name, "Charlie");
    records[2].age = 21;
    int search_id = 102;
    Student* student = search_student(records, n, search_id);
    if (student != NULL) {
        printf("Student ID: %d, Name: %s, Age: %d\n", student->id, student->name, student->age);
    } else {
        printf("Student not found.\n");
    }
    free(records);
    return 0;
}
