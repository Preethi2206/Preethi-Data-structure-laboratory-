#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct Product {
    int product_id;
    char name[100];
    struct Product* next;
} Product;
Product* hash_table[TABLE_SIZE];
unsigned int hash(int product_id) {
    return product_id % TABLE_SIZE;
}
void add_product(int product_id, const char* name) {
    unsigned int index = hash(product_id);
    Product* new_product = (Product*)malloc(sizeof(Product));
    new_product->product_id = product_id;
    strcpy(new_product->name, name);
    new_product->next = hash_table[index];
    hash_table[index] = new_product;
}
Product* get_product(int product_id) {
    unsigned int index = hash(product_id);
    Product* temp = hash_table[index];
    while (temp) {
        if (temp->product_id == product_id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
int main() {
    add_product(101, "Laptop");
    add_product(102, "Smartphone");
    Product* product = get_product(101);
    if (product) {
        printf("Product ID: %d, Name: %s\n", product->product_id, product->name);
    } else {
        printf("Product not found.\n");
    }
    return 0;
}
