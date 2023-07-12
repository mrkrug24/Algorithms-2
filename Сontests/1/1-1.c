#include <stdio.h>

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);

    int min, max;
    min = max = x;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);

        if (x < min) {
            min = x;
        } else if (x > max) {
            max = x;
        }
    }

    printf("%d", max - min);

    
    return 0;
}
