#include <stdio.h>
#include <stdlib.h>

int **createBoard(int n) {
    int **board = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        board[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

void showBoard(int n, int **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-d ", a[i][j]);
        }
        printf("\n");
    }
    printf("============\n");
}

int validMove(int i, int j, int n, int **a) {
    if (i < 0 || i > n - 1 || j < 0 || j > n - 1) return 0;
    if (a[i][j]!=0)return 0;
    return 1;
}

int knightMove(int n, int **a, int x, int y, int step) {
    int posX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int posY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    if (step > n * n) {
        showBoard(n, a);
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        int row = x + posX[i];
        int col = y + posY[i];
        if (validMove(row, col, n, a)) {
            a[row][col] = step;
            knightMove(n, a, row, col, step + 1);
            a[row][col] = 0;
        }
    }
}
int main() {
    int n;
    printf("The chess table has the size N x N. Let N be:");
    scanf("%d", &n);
    int **a = createBoard(n);
    a[0][0]=1;
    knightMove(n, a, 0, 0, 2);
    return 0;
}