#include <stdio.h>
void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }
void P(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
void heapify(int a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void HS(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
int main() {
    int a[] = {12, 11, 13, 5, 6, 7}, n = sizeof(a) / sizeof(a[0]);
    printf("Original array: \n"); P(a, n);
    HS(a, n);
    printf("\nSorted array: \n"); P(a, n);
    return 0;
}
