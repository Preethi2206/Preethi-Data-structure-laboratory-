#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100
#define ITEM_LENGTH 50
char shoppingList[MAX_ITEMS][ITEM_LENGTH];
int itemCount = 0;
void add_item(const char* item) {
    if (itemCount < MAX_ITEMS) {
        strncpy(shoppingList[itemCount], item, ITEM_LENGTH);
        itemCount++;
    }
}
void remove_item(const char* item) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(shoppingList[i], item) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                strcpy(shoppingList[j], shoppingList[j + 1]);
            }
            itemCount--;
            return;
        }
    }
}
void display_list() {
    if (itemCount == 0) {
        printf("Shopping list is empty.\n");
    } else {
        printf("Shopping List:\n");
        for (int i = 0; i < itemCount; i++) {
            printf("%s\n", shoppingList[i]);
        }
    }
}
int main() {
    add_item("Milk");
    add_item("Eggs");
    display_list();
    remove_item("Milk");
    display_list();
    return 0;
}
