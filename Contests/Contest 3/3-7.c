#include <stdio.h>
#include <math.h>

#define N 4

int max(int x, int y) {
    return (x > y) ? x : y;
}

int mod(int a, int bc, int m) {
    if (bc == 1) {
        return a % m;
    }

    if (bc == 2) {
        return (a * a) % m;
    }

    int chang = (((a * a) % m) * a) % m;

    return ((mod(chang, bc / 3, m) % m * ((int) pow(a, (bc % 3)) % m)) % m);
}

int main(void) {
    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = 0;

    for (int a = 0; a < N - 1; a++) {
        for (int b = 0; b < N - 1; b++) {
            if (a == b) {
                continue;
            }

            for (int c = 0; c < N - 1; c++) {
                if (a != c && b != c) {
                    int bc = pow(arr[b], arr[c]);
                    int y = mod(arr[a], bc, arr[N - 1]);
                    ans = max(ans, y);
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}