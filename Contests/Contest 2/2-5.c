#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int cnt = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 2; j < n; j += 2) {
            if (a[(i + j) / 2] * 2 == a[i] + a[j]) {
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}