#include <stdio.h>

#define SIZE 8
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int main(void) {
    int in_front[SIZE];
    int on_right[SIZE];
    
    int max_front = 0;
    int max_right = 0;

    for (int i = 0; i < 2 * SIZE; i++) {
        int high;
        scanf("%d", &high);

        if (i < SIZE) {
            max_front = max(high, max_front);
            in_front[i] = high;
        } else {
            max_right = max(high, max_right);
            on_right[i - SIZE] = high;
        }
    }

    if (max_front != max_right) {
        printf("-1");
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ans += min(in_front[i], on_right[j]);
        }
    }

    printf("%d", ans);

    return 0;
}