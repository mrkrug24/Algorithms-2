#include <stdio.h>

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int num = 0;
    int den = 1;

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        num = a * den + num * b;
        den *= b;
    }

    if (num != 0) {
        int res = gcd(num, den);
        num /= res;
        den /= res;
    } else {
        den = 1;
    }

    int integ = 0;

    if (num >= den) {
        integ = num / den;
        num %= den;
    }

    printf("%d %d %d", integ, num, den);

    return 0;
}