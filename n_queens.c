#include <stdbool.h>
#include <stdio.h>
#define N 4
void print(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf(board[i][j] ? "Q " : ". ");
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N], int r, int c) {
    for (int i = 0; i < c; i++) if (board[r][i]) return false;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = r, j = c; j >= 0 && i < N; i++, j--) if (board[i][j]) return false;
    return true;
}
bool solve(int board[N][N], int c) {
    if (c >= N) return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, c)) {
            board[i][c] = 1;
            if (solve(board, c + 1)) return true;
            board[i][c] = 0;
        }
    }
    return false;
}
int main() {
    int board[N][N] = {0};
    if (solve(board, 0)) print(board);
    else printf("Solution does not exist");
    return 0;
}
