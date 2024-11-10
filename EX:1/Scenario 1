#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;
Contact contactList[MAX_CONTACTS];
int contactCount = 0;
void add_contact(const char* name, const char* phone) {
    if (contactCount < MAX_CONTACTS) {
        strcpy(contactList[contactCount].name, name);
        strcpy(contactList[contactCount].phone, phone);
        contactCount++;
    }
}
void delete_contact(const char* name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contactList[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contactList[j] = contactList[j + 1];
            }
            contactCount--;
            return;
        }
    }
}
void display_contacts() {
    for (int i = 0; i < contactCount; i++) {
        printf("Name: %s, Phone: %s\n", contactList[i].name, contactList[i].phone);
    }
}
int main() {
    add_contact("Alice", "123-456-7890");
    add_contact("Bob", "987-654-3210");
    display_contacts();
    delete_contact("Alice");
    display_contacts();
    return 0;
}
