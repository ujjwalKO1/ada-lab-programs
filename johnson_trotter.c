#include <stdio.h>

#define LEFT 0
#define RIGHT 1

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    printf(" ");
}

void johnsonTrotter(int n) {
    int a[n];
    int dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printArray(a, n);

    while (1) {
        int mobile_val = -1;
        int mobile_idx = -1;

        for (int i = 0; i < n; i++) {
            
            if (dir[i] == LEFT && i > 0 && a[i] > a[i - 1]) {
                if (a[i] > mobile_val) {
                    mobile_val = a[i];
                    mobile_idx = i;
                }
            }
            
            else if (dir[i] == RIGHT && i < n - 1 && a[i] > a[i + 1]) {
                if (a[i] > mobile_val) {
                    mobile_val = a[i];
                    mobile_idx = i;
                }
            }
        }

        if (mobile_idx == -1) {
            break;
        }

        int swap_idx = (dir[mobile_idx] == LEFT) ? mobile_idx - 1 : mobile_idx + 1;

        int temp_a = a[mobile_idx];
        a[mobile_idx] = a[swap_idx];
        a[swap_idx] = temp_a;

        int temp_dir = dir[mobile_idx];
        dir[mobile_idx] = dir[swap_idx];
        dir[swap_idx] = temp_dir;

        for (int i = 0; i < n; i++) {
            if (a[i] > mobile_val) {
                
                dir[i] = 1 - dir[i]; 
            }
        }

        printArray(a, n);
    }
    printf("\n");
}

int main() {
    int n = 3;
    printf("Johnson-Trotter permutations for n = %d:\n", n);
    johnsonTrotter(n);
    
    return 0;
}
