#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[100];
    char phone_number[20];
} Contact;
Contact* search_contact(Contact* contacts, int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}
int main() {
    int n = 3;
    Contact* contacts = (Contact*)malloc(n * sizeof(Contact));
    strcpy(contacts[0].name, "Alice");
    strcpy(contacts[0].phone_number, "123-456-7890");
    strcpy(contacts[1].name, "Bob");
    strcpy(contacts[1].phone_number, "987-654-3210");
    strcpy(contacts[2].name, "Charlie");
    strcpy(contacts[2].phone_number, "555-123-4567");
    const char* search_name = "Bob";
    Contact* contact = search_contact(contacts, n, search_name);
    if (contact != NULL) {
        printf("Name: %s, Phone: %s\n", contact->name, contact->phone_number);
    } else {
        printf("Contact not found.\n");
    }
    free(contacts);
    return 0;
}
