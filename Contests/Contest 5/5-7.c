#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 200

int main(void) {
    char s[N + 1];
    scanf("%200s", s);

    int len_s = strlen(s);
    int len_a = 0;
    int len_b = 0;
    int len_c = 0;

    int k = 0;

    for (int i = 0; i < len_s; i++) {

        if (k == 2) {
            len_c++;
        }

        if (k == 1) {
            if (s[i] != '=') {
                len_b++;
            } else {
                k = 2;
            }
        }

        if (k == 0) {
            if (s[i] != '+') {
                len_a++;
            } else {
                k = 1;
            }
        }
    }

     printf("%d %d %d \n", len_a, len_b, len_c);

    int a[len_a];
    int b[len_b];
    int c[len_c];

    for (int i = 0; i < len_a; i++) {
        int x = s[i] - '0';
        a[i] = x;
    }

    for (int i = 0; i < len_b; i++) {
        int x = s[len_a + 1 + i] - '0';
        b[i] = x;
    }

    for (int i = 0; i < len_c; i++) {
        int x = s[len_a + len_b + 2 + i] - '0';
        c[i] = x;
    }

    for (int i = 0; i < len_a; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (int i = 0; i < len_b; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    for (int i = 0; i < len_c; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}