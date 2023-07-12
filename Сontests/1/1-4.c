#include <math.h>
#include <stdio.h>

#define swap(a, b) { int tmp = a; a = b; b = tmp; }

int main(void) {
    int n, first, second, third;
    scanf("%d %d %d %d", &n, &first, &second, &third);

    if (first < second) {
        swap(first, second);
    }

    if (third >= first) {
        swap(first, third);
        swap(second, third);
    } else if (first > third && third > second) {
        swap(second, third);
    }

    int x;

    for (int i = 3; i < n; i++) {
        scanf("%d", &x);

        if (x >= first) {
            third = second;
            second = first;
            first = x;
        } else if (x >= second) {
            third = second;
            second = x;
        } else if (x >= third) {
            third = x;
        }
    }

    printf("%d %d %d", first, second, third);

    return 0;
}
