#include <stdio.h>

int main(void) {
    double x;
    int n;

    scanf("%lf", &x);
    scanf("%d", &n);

    int sign = -1;
    double x_pow = x;
    double ans = x_pow;
    long fact = 1;

    for (int i = 3; i <= 1 + 2 * (n - 1); i += 2) {
        x_pow *= x * x;
        fact *= (i - 1) * i;

        ans += sign * x_pow / fact;
        sign = -sign;
    }

    printf("%.6lf", ans);

    return 0;
}
