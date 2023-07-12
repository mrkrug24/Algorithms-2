#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void move(int** matrix, int n, int x, int y, int move, int* cnt_new, int** coord_2) {
    if (x - 2 >= 0 && y - 1 >= 0 && matrix[x - 2][y - 1] == 0) {
        matrix[x - 2][y - 1] = move;
        coord_2[*cnt_new][0] = x - 2;
        coord_2[*cnt_new][1] = y - 1;
        *cnt_new += 1;
    }

    if (x - 2 >= 0 && y + 1 < n && matrix[x - 2][y + 1] == 0) {
        matrix[x - 2][y + 1] = move;
        coord_2[*cnt_new][0] = x - 2;
        coord_2[*cnt_new][1] = y + 1;
        *cnt_new += 1;
    }

    if (x - 1 >= 0 && y - 2 >= 0 && matrix[x - 1][y - 2] == 0) {
        matrix[x - 1][y - 2] = move;
        coord_2[*cnt_new][0] = x - 1;
        coord_2[*cnt_new][1] = y - 2;
        *cnt_new += 1;
    }

    if (x - 1 >= 0 && y + 2 < n && matrix[x - 1][y + 2] == 0) {
        matrix[x - 1][y + 2] = move;
        coord_2[*cnt_new][0] = x - 1;
        coord_2[*cnt_new][1] = y + 2;
        *cnt_new += 1;
    }

    if (x + 1 < n && y - 2 >= 0 && matrix[x + 1][y - 2] == 0) {
        matrix[x + 1][y - 2] = move;
        coord_2[*cnt_new][0] = x + 1;
        coord_2[*cnt_new][1] = y - 2;
        *cnt_new += 1;
    }

    if (x + 1 < n && y + 2 < n && matrix[x + 1][y + 2] == 0) {
        matrix[x + 1][y + 2] = move;
        coord_2[*cnt_new][0] = x + 1;
        coord_2[*cnt_new][1] = y + 2;
        *cnt_new += 1;
    }

    if (x + 2 < n && y - 1 >= 0 && matrix[x + 2][y - 1] == 0) {
        matrix[x + 2][y - 1] = move;
        coord_2[*cnt_new][0] = x + 2;
        coord_2[*cnt_new][1] = y - 1;
        *cnt_new += 1;
    }

    if (x + 2 < n && y + 1 < n && matrix[x + 2][y + 1] == 0) {
        matrix[x + 2][y + 1] = move;
        coord_2[*cnt_new][0] = x + 2;
        coord_2[*cnt_new][1] = y + 1;
        *cnt_new += 1;
    }

    return;
}

int main(void) {
    int n, x_n, y_n, x_k, y_k;
    scanf("%d %d %d %d %d", &n, &x_n, &y_n, &x_k, &y_k);

    if (x_n == x_k && y_n == y_k) {
        printf("%d", 0);
        return 0;
    }

    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    matrix[x_n - 1][y_n - 1] = 1;

    int step = 1;
    int cnt = 1;

    int** coord_prev = (int**)malloc(n * n * sizeof(int*));
    for (int i = 0; i < n * n; i++) {
        coord_prev[i] = (int*)malloc(2 * sizeof(int));
    }

    coord_prev[cnt - 1][0] = x_n - 1;
    coord_prev[cnt - 1][1] = y_n - 1;

    int** coord_cur = (int**)malloc(n * n * sizeof(int*));
    for (int i = 0; i < n * n; i++) {
        coord_cur[i] = (int*)malloc(2 * sizeof(int));
    }

    while (matrix[x_k - 1][y_k - 1] == 0 && cnt != 0) {
        int cnt_new = cnt;
        cnt = 0;

        for (int i = 0; i < cnt_new; i++) {
            int x = coord_prev[i][0];
            int y = coord_prev[i][1];

            move(matrix, n, x, y, step, &cnt, coord_cur);
        }

        for (int i = 0; i < cnt; i++) {
            coord_prev[i][0] = coord_cur[i][0];
            coord_prev[i][1] = coord_cur[i][1];
        }

        step++;
    }

    if (matrix[x_k - 1][y_k - 1] != 0) {
        printf("%d", step - 1);
    } else {
        printf("%d", -1);
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }

    free(matrix);

    for (int i = 0; i < n * n; i++) {
        free(coord_prev[i]);
        free(coord_cur[i]);
    }

    free(coord_prev);
    free(coord_cur);

    return 0;
}