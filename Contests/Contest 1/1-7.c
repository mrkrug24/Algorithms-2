#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    x = abs(x);
    y = abs(y);

    int abs_diff = abs(x - y);

    int min = x < y ? x : y;

    int ans = (min + abs_diff) * 2 - abs_diff % 2;

    printf("%d", ans);

    return 0;
}