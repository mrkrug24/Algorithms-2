#include <math.h>
#include <stdio.h>

#define sqr(x) ((x) * (x))
#define swap(a, b) { double tmp = a; a = b; b = tmp; }

int main(void) {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &c, &d, &a, &b);

    if (a < b) {
        swap(a, b);
    }

    if (c < d) {
        swap(c, d);
    }

    int ans = 0;

    if (a <= c && b <= d) {
        ans = 1;
    } else if (a > c && a > b && a * b <= c * d) {
        double criteria = sqr(c + d) / sqr(a + b) + sqr(c - d) / sqr(a - b);

        if (criteria >= 2) {
            ans = 1;
        }
    }

    if (ans) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
