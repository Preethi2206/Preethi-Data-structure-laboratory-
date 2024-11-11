#include <stdio.h>
#include <stdlib.h>
void sort_prices(float* prices, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[i] > prices[j]) {
                float temp = prices[i];
                prices[i] = prices[j];
                prices[j] = temp;
            }
        }
    }
}
int main() {
    int n = 5;
    float* prices = (float*)malloc(n * sizeof(float));
    prices[0] = 19.99;
    prices[1] = 5.99;
    prices[2] = 12.49;
    prices[3] = 8.99;
    prices[4] = 25.00;
    sort_prices(prices, n);
    printf("Sorted Prices:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", prices[i]);
    }
    free(prices);
    return 0;
}
