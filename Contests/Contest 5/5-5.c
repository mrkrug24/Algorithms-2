#include <stdio.h>
#include <stdlib.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

void fill_cell(int **x, int i, int j, int n, int m) {
    if (i == 0) {
        x[i][j] += max(x[i][j - 1], x[i + 1][j - 1]);
    }

    if (i == n - 1) {
        x[i][j] += max(x[i - 1][j - 1], x[i][j - 1]);
    }

    if (i > 0 && i < n - 1) {
        x[i][j] += max(max(x[i - 1][j - 1], x[i][j - 1]), max(x[i][j - 1], x[i + 1][j - 1]));
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(long));
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    long ans = 0;

    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            fill_cell(matrix, i, j, n, m);

            if (j == m - 1) {
                if (ans < matrix[i][j]) {
                    ans = matrix[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }

    free(matrix);

    printf("%ld", ans);

    return 0;
}