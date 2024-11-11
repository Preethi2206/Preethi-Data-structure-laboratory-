#include <stdio.h>
#include <stdlib.h>
void sort_ages(int* ages, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ages[i] > ages[j]) {
                int temp = ages[i];
                ages[i] = ages[j];
                ages[j] = temp;
            }
        }
    }
}
int main() {
    int n = 5;
    int* ages = (int*)malloc(n * sizeof(int));
    ages[0] = 34;
    ages[1] = 25;
    ages[2] = 58;
    ages[3] = 22;
    ages[4] = 45;
    sort_ages(ages, n);
    printf("Sorted Ages:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", ages[i]);
    }
    free(ages);
    return 0;
}
