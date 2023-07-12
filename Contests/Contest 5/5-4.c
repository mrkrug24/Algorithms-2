#include <stdio.h>
#include <stdlib.h>

void spread(int x, int y, int n, int m, int* k, int* cnt, int** matrix, int **new_infected) {
    if (x > 0 && matrix[y][x - 1] == 0) {
        matrix[y][x - 1] = 1;
        *cnt += 1;
        *k += 1;

        new_infected[*k - 1][0] = x - 1;
        new_infected[*k - 1][1] = y;
    }

    if (y > 0 && matrix[y - 1][x] == 0) {
        matrix[y - 1][x] = 1;
        *cnt += 1;
        *k += 1;

        new_infected[*k - 1][0] = x;
        new_infected[*k - 1][1] = y - 1;
    }

    if (x < m - 1 && matrix[y][x + 1] == 0) {
        matrix[y][x + 1] = 1;
        *cnt += 1;
        *k += 1;

        new_infected[*k - 1][0] = x + 1;
        new_infected[*k - 1][1] = y;
    }

    if (y < n - 1 && matrix[y + 1][x] == 0) {
        matrix[y + 1][x] = 1;
        *cnt += 1;
        *k += 1;

        new_infected[*k - 1][0] = x;
        new_infected[*k - 1][1] = y + 1;
    }

    return;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int time = 0;
    int quantity = n * m;

    int** matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(m, sizeof(int));
    }

    int** last_infected = (int**)malloc(sizeof(int*) * quantity);
    for (int i = 0; i < quantity; i++) {
        last_infected[i] = (int*)malloc(sizeof(int) * 2);
    }

    int** new_infected = (int**)malloc(sizeof(int*) * quantity);
    for (int i = 0; i < quantity; i++) {
        new_infected[i] = (int*)malloc(sizeof(int) * 2);
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        last_infected[i][0] = x - 1;
        last_infected[i][1] = y - 1;
        matrix[y - 1][x - 1] = 1;
    }

    int cnt_new = k;
    int cnt_all = k;

    while (cnt_all < quantity) {
        cnt_new = k;
        k = 0;

        for (int i = 0; i < cnt_new; i++) {
            int x = last_infected[i][0];
            int y = last_infected[i][1];
            spread(x, y, n, m, &k, &cnt_all, matrix, new_infected);
        }

        for (int i = 0; i < k; i++) {
            last_infected[i][0] = new_infected[i][0];
            last_infected[i][1] = new_infected[i][1];
        }

        time++;
    }

    printf("%d", time);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }

    free(matrix);

    for (int i = 0; i < quantity; i++) {
        free(last_infected[i]);
        free(new_infected[i]);
    }

    free(last_infected);
    free(new_infected);

    return 0;
}