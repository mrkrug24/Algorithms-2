#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[arr[arr[i] - 1] - 1]);
    }

    return 0;
}