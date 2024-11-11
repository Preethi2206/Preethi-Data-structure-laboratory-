#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort_titles(char** titles, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(titles[i], titles[j]) > 0) {
                char* temp = titles[i];
                titles[i] = titles[j];
                titles[j] = temp;
            }
        }
    }
}
int main() {
    int n = 5;
    char** titles = (char**)malloc(n * sizeof(char*));
    titles[0] = "The Catcher in the Rye";
    titles[1] = "To Kill a Mockingbird";
    titles[2] = "1984";
    titles[3] = "Pride and Prejudice";
    titles[4] = "Moby Dick";
    sort_titles(titles, n);
    printf("Sorted Titles:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", titles[i]);
    }
    free(titles);
    return 0;
}
