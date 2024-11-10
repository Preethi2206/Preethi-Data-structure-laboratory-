#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
typedef struct Article {
    char title[100];
    char content[500];
    struct Article* next;
} Article;
Article* hash_table[TABLE_SIZE];
unsigned int hash(const char* title) {
    unsigned int hash_val = 0;
    for (int i = 0; title[i] != '\0'; i++) {
        hash_val = (hash_val * 31 + title[i]) % TABLE_SIZE;
    }
    return hash_val;
}
void add_article(const char* title, const char* content) {
    unsigned int index = hash(title);
    Article* new_article = (Article*)malloc(sizeof(Article));
    strcpy(new_article->title, title);
    strcpy(new_article->content, content);
    new_article->next = hash_table[index];
    hash_table[index] = new_article;
}
Article* get_article(const char* title) {
    unsigned int index = hash(title);
    Article* temp = hash_table[index];
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
int main() {
    add_article("Article 1", "Content of Article 1");
    add_article("Article 2", "Content of Article 2");
    Article* article = get_article("Article 1");
    if (article) {
        printf("Title: %s\nContent: %s\n", article->title, article->content);
    } else {
        printf("Article not found.\n");
    }
    return 0;
}
