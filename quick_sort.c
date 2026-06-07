#include <stdio.h>
void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }
void P(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
int part(int a[], int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++)
        if (a[j] < p) swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[h]);
    return i + 1;
}
void QS(int a[], int l, int h) {
    if (l < h) {
        int p = part(a, l, h);
        QS(a, l, p - 1);
        QS(a, p + 1, h);
    }
}
int main() {
    int a[] = {10, 80, 30, 90, 40, 50, 70}, n = sizeof(a) / sizeof(a[0]);
    printf("Original array: \n"); P(a, n);
    QS(a, 0, n - 1);
    printf("\nSorted array: \n"); P(a, n);
    return 0;
}
