#include <stdio.h>
#include <string.h>

#define N 100
#define MAX 10

int find(int i, int digit, char s[], int n) {
    char x = (char) digit + '0';

    for (; i < n; i++) {
        if (s[i] == x) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    char s[N + 2];
    scanf("%s", s);

    int len_s = strlen(s);

    if (len_s < 3) {
        printf("%d", 0);
        return 0;
    }

    int cnt_var = 0;

    for (int i = 1; i < MAX; i++) {
        int first = find(0, i, s, len_s);

        if (first == -1) {
            continue;
        }

        for (int j = 0; j < MAX; j++) {
            int second = find(first + 1, j, s, len_s);

            if (second == -1) {
                continue;
            }

            for (int k = 0; k < MAX; k++) {
                int third = find(second + 1, k, s, len_s);

                if (third == -1) {
                    continue;
                }

                cnt_var++;
            }
        }
    }

    printf("%d", cnt_var);

    return 0;
}