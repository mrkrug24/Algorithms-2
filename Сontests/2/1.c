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

    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}