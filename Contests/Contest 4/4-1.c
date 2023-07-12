#include <stdio.h>
#include <string.h>

#define LEN 255

int main(void) {
    char s[LEN + 1];
    scanf("%255s", s);
    int len_s = strlen(s);

    int a[LEN];
    int len_a = 0;

    for (int i = 0; i < len_s; i++) {
        if (s[i] == 'A') {
            a[len_a] = i;
            len_a++;
        }
    }

    for (int i = 0; i < len_s; i++) {
        int cnt_even = 0;
        int cnt_odd = 0;

        for (int j = 0; j < len_a; j++) {
            if (a[j] < i) {
                if (a[j] % 2 == 0) {
                    cnt_even++;
                } else {
                    cnt_odd++;
                }
            }

            if (a[j] > i) {
                if (a[j] % 2 == 0) {
                    cnt_odd++;
                } else {
                    cnt_even++;           
                }
            }
        }

        if (cnt_even == cnt_odd) {
            printf("%d ", i + 1);
        }
    }

    return 0;
}