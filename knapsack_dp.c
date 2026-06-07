#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int KS(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
            K[i][w] = (i == 0 || w == 0) ? 0 :
                      (wt[i - 1] <= w) ? max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]) :
                      K[i - 1][w];
    return K[n][W];
}
int main() {
    int val[] = {60, 100, 120}, wt[] = {10, 20, 30}, W = 50, n = 3;
    printf("Total Knapsack Capacity: %d\n", W);
    printf("Maximum value we can pack: %d\n", KS(W, wt, val, n));
    return 0;
}
