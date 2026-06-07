#include <stdio.h>
void P(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d", a[i]);
    printf(" ");
}
void JT(int n) {
    int a[n], dir[n];
    for (int i = 0; i < n; i++) { a[i] = i + 1; dir[i] = 0; }
    P(a, n);
    while (1) {
        int val = -1, idx = -1;
        for (int i = 0; i < n; i++) {
            if (dir[i] == 0 && i > 0 && a[i] > a[i - 1] && a[i] > val) { val = a[i]; idx = i; }
            if (dir[i] == 1 && i < n - 1 && a[i] > a[i + 1] && a[i] > val) { val = a[i]; idx = i; }
        }
        if (idx == -1) break;
        int swp = dir[idx] == 0 ? idx - 1 : idx + 1;
        int t = a[idx]; a[idx] = a[swp]; a[swp] = t;
        t = dir[idx]; dir[idx] = dir[swp]; dir[swp] = t;
        for (int i = 0; i < n; i++) if (a[i] > val) dir[i] = 1 - dir[i];
        P(a, n);
    }
    printf("\n");
}
int main() {
    printf("Johnson-Trotter permutations for n = 3:\n");
    JT(3);
    return 0;
}
