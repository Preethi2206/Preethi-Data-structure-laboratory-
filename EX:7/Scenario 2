#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char username[100];
    char name[100];
} User;
User* search_user(User* users, int n, const char* username) {
    for (int i = 0; i < n; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}
int main() {
    int n = 3;
    User* users = (User*)malloc(n * sizeof(User));
    strcpy(users[0].username, "alice123");
    strcpy(users[0].name, "Alice");
    strcpy(users[1].username, "bob456");
    strcpy(users[1].name, "Bob");
    strcpy(users[2].username, "charlie789");
    strcpy(users[2].name, "Charlie");
    const char* search_username = "bob456";
    User* user = search_user(users, n, search_username);
    if (user != NULL) {
        printf("Username: %s, Name: %s\n", user->username, user->name);
    } else {
        printf("User not found.\n");
    }
    free(users);
    return 0;
}
