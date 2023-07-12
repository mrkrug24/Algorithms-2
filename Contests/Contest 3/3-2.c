#include <stdio.h>
#include <math.h>

int is_prime(int x) {
    if (x == 1) {
        return 0;
    }

    int res = 1;

    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) {
            res = 0;
            break;
        }
    }

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (!is_prime(n)) {
        n++;
    }

    printf("%d", n);

    return 0;
}