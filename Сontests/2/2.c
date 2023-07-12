#include <stdio.h>

#define MAX_LEN 10000

int main(void) {
    int arr[MAX_LEN];
    int n = 0;

    int elem;
    scanf("%d", &elem);

    while (elem != 0) {
        arr[n++] = elem;
        scanf("%d", &elem);
    }

    for (int i = 0; i < n; i += 2) {
        printf("%d ", arr[i]);
    }

    for (int i = n - (n % 2) - 1; i > 0; i -= 2) {
        printf("%d ", arr[i]);
    }

    return 0;
}