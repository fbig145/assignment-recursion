#include <stdio.h>
#include <stdlib.h>

int info(int *m, int *n) {
    printf("m=");
    scanf("%d", m);
    printf("n=");
    scanf("%d", n);
}

int **Matrix(int m, int n) {
    int **matrix = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void getMatrix(int m, int n, int **a) {
    printf("\nPlease insert the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void getStart(int *i, int *j, int **a) {
    printf("i=");
    scanf("%d", i);
    printf("j=");
    scanf("%d", j);
    while (a[*i][*j] == 0) {
        printf("Not a valid starting point!\n");
        printf("i=");
        scanf("%d", i);
        printf("j=");
        scanf("%d", j);
    }
    printf("\n");
}
void freeMatrix(int **a, int m){
    for (int i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);
}
int isExit(int **a, int lin, int col, int m, int n){
    return (a[lin][col]!=0 && (lin == 0 || lin == m - 1 || col == 0 || col == n - 1));
}
void printMatrix(int **a, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%-d ", a[i][j]);
        }
        printf("\n");
    }
    printf("===========\n");
}

int goodMove(int i, int j, int m, int n, int **a) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) return 0;
    if (a[i][j]==0) return 0;
    if(a[i][j]>=2) return 0;
    return 1;
}

int findExit(int **a, int m, int n, int i, int j, int step) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int k = 0; k < 4; k++) {
        int row = i + dx[k];
        int col = j + dy[k];
        if (goodMove(row, col, m, n, a)) {
            a[row][col] = step;
            if (row == 0 || row == m - 1 || col == 0 || col == n - 1) {
                printMatrix(a, m, n);
                a[row][col]=1;
                return 0;
            }else findExit(a, m, n, row, col, step + 1);
            a[row][col] = 1;
        }
    }
}
int main() {
    int m, n, i,j;
    info(&m, &n);
    int **a = Matrix(m, n);
    getMatrix(m, n, a);
    getStart(&i, &j, a);
    a[i][j]=2;
    if(isExit(a,i,j,m,n)){
        printMatrix(a,m,n);
    }
    findExit(a, m, n, i, j,3);
    freeMatrix(a,m);
    return 0;
}