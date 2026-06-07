#include <stdio.h>
#include <stdlib.h>
struct Item { int value, weight; };
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 < r2) - (r1 > r2);
}
double FK(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);
    int curW = 0;
    double val = 0;
    for (int i = 0; i < n; i++) {
        if (curW + arr[i].weight <= W) {
            curW += arr[i].weight;
            val += arr[i].value;
        } else {
            val += arr[i].value * ((double)(W - curW) / arr[i].weight);
            break;
        }
    }
    return val;
}
int main() {
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50, n = 3;
    printf("Total Knapsack Capacity: %d\n", W);
    printf("Maximum value we can pack: %.2f\n", FK(W, arr, n));
    return 0;
}
