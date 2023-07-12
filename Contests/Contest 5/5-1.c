#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long trace;
    int first = 0;

    int** ans = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(long) * n);
    }

    int size_ans = 0;

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);

        int** x = (int**)malloc(sizeof(int*) * m);

        long long cnt = 0;

        for (int j = 0; j < m; j++) {
            x[j] = (int*)malloc(sizeof(long) * m);

            for (int k = 0; k < m; k++) {
                scanf("%d", &x[j][k]);

                if (j == k) {
                    cnt += x[j][k];
                }
            }
        }

        if (first == 0) {
            trace = cnt;
        }

        if (trace < cnt || first == 0) {
            first = 1;
            trace = cnt;
            size_ans = m;

            ans = (int**)realloc(ans, sizeof(int*) * m);

            for (int i = 0; i < m; i++) {
                ans[i] = (int*)realloc(ans[i], sizeof(long) * m);

                for (int j = 0; j < m; j++) {
                    ans[i][j] = x[i][j];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            free(x[i]);
        }

        free(x);
    }

    for (int i = 0; i < size_ans; i++) {
        for (int j = 0; j < size_ans; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size_ans; i++) {
        free(ans[i]);
    }

    free(ans);

    return 0;
}