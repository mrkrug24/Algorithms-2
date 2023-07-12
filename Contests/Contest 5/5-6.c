#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIGITS 10

long long mypow(long long a, int n) {
    return (n == 0) ? 1 : a * mypow(a, n - 1);
}

int is_prime(long long x) {
    if (x == 1) {
        return 0;
    }

    int res = 1;
    int root = sqrt(x);

    for (int i = 2; i <= root; i++) {
        if (x % i == 0) {
            res = 0;
            break;
        }
    }

    return res;
}

void find_ans(long long x, long long first, long long last) {
    if (x > last) {
        return;
    }

    if (x >= first) {
        printf("%lld ", x);
        return;
    }

    for (int i = 0; i < DIGITS; i++) {
        if (is_prime(x * 10 + i)) {
            find_ans(x * 10 + i, first, last);
        }
    }

    return;
}

int main(void) {
    int n;
    scanf("%d", &n);

    long long first = mypow(10, n - 1);
    long long last = mypow(10, n) - 1;

    for (int x = 1; x < DIGITS; x++) {
        if (is_prime(x)) {
            find_ans(x, first, last);
        }
    }

    return 0;
}