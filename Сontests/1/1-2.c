#include <stdio.h>

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);

    int max = x;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);

        if (x > max) {
            max = x;
            ans = 1;
        } else if (x == max) {
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}
