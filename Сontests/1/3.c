#include <stdio.h>
#include <math.h>

#define max(x, y) ((x > y) ? (x) : (y))

int main(void) {
    int n, left, right;
    scanf("%d %d", &n, &left);

    int len_tmp = 1;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        scanf("%d", &right);

        if (right > left) {
            len_tmp++;
        } else {
            ans = max(ans, len_tmp);
            len_tmp = 1;
        }

        left = right;
    }

    ans = max(ans, len_tmp);

    printf("%d", ans);

    return 0;
}