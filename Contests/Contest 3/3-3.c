#include <stdio.h>

#define swap(a, b) { int tmp = a; a = b; b = tmp; }

int med(int a, int b, int c) {
    if (a < b) {
        swap(a, b);
    }

    if (c >= a) {
        swap(a, c);
        swap(b, c);
    } else if (c > b) {
        swap(b, c);
    }

    return b;
}

int main(void) {
    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int n = size;

    while (n != 1) {
        for (int i = 0; i < n - 2; i++) {
            arr[i] = med(arr[i], arr[i + 1], arr[i + 2]);
        }

        n -= 2;
    }

    printf("%d", arr[0]);

    return 0;
}