#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10

int main(void) {
    long long x;
    scanf("%lld", &x);

    int len = INIT_SIZE;
    int i = 0;

    int* ans = (int*)malloc(sizeof(long long) * len);

    while (x != 0) {
        if (i == len) {
            len *= 2;
            ans = (int*)realloc(ans, sizeof(long long) * len);
        }

        ans[i++] = x;
        scanf("%lld", &x);
    }

    for (int j = 0; j < i; j += 2) {
        printf("%d ", ans[j]);
    }

    for (int j = 1; j < i; j += 2) {
        printf("%d ", ans[j]);
    }

    free(ans);

    return 0;
}