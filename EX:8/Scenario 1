#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct User {
    char username[100];
    struct User* next;
} User;
User* hash_table[TABLE_SIZE];
unsigned int hash(const char* username) {
    unsigned int hash_val = 0;
    for (int i = 0; username[i] != '\0'; i++) {
        hash_val = (hash_val * 31 + username[i]) % TABLE_SIZE;
    }
    return hash_val;
}
int add_user(const char* username) {
    unsigned int index = hash(username);
    User* new_user = (User*)malloc(sizeof(User));
    strcpy(new_user->username, username);
    new_user->next = hash_table[index];
    hash_table[index] = new_user;
    return 1;
}
int user_exists(const char* username) {
    unsigned int index = hash(username);
    User* temp = hash_table[index];
    while (temp) {
        if (strcmp(temp->username, username) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main() {
    add_user("alice");
    add_user("bob");
    if (user_exists("alice")) {
        printf("User 'alice' exists.\n");
    } else {
        printf("User 'alice' does not exist.\n");
    }
    if (user_exists("charlie")) {
        printf("User 'charlie' exists.\n");
    } else {
        printf("User 'charlie' does not exist.\n");
    }
    return 0;
}
