#include <stdio.h>
void P(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
void M(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, L[n1], R[n2], i, j, k;
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    for (i = j = 0, k = l; i < n1 && j < n2; k++)
        a[k] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}
void MS(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MS(a, l, m);
        MS(a, m + 1, r);
        M(a, l, m, r);
    }
}
int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10}, n = sizeof(a) / sizeof(a[0]);
    printf("Original array: \n"); P(a, n);
    MS(a, 0, n - 1);
    printf("\nSorted array: \n"); P(a, n);
    return 0;
}
