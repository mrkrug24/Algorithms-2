#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    int ans = 1;

    for (int i = 0; i < n; i++) {
        int elem;
        scanf("%d", &elem);

        if (elem > n || elem < 0) {
            ans = 0;
            break;
        }

        if (arr[elem - 1]) {
            ans = 0;
            break;
        }

        arr[elem - 1] = 1;
    }

    if (ans) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}