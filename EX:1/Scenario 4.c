#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASK_LENGTH 100
typedef struct Task {
    char task[MAX_TASK_LENGTH];
    struct Task* next;
} Task;
Task* head = NULL;
void add_task(const char* task_name) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->task, task_name);
    newTask->next = head;
    head = newTask;
}
void remove_task() {
    if (head == NULL) {
        printf("No tasks to remove.\n");
        return;
    }
    Task* temp = head;
    if (temp->next == NULL) { 
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void display_tasks() {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }
    Task* temp = head;
    while (temp) {
        printf("%s\n", temp->task);
        temp = temp->next;
    }
}
int main() {
    add_task("Task 1");
    add_task("Task 2");
    add_task("Task 3");
    printf("Tasks:\n");
    display_tasks(); 
    remove_task();   
    printf("\nUpdated Tasks:\n");
    display_tasks();
    return 0;
}
