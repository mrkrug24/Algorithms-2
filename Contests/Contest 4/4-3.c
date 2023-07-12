#include <stdio.h>
#include <string.h>

#define LEN 1000000

void insert_space(char s[], int equal, int remains, int j) {
    int stop = j + equal;

    for (; j < stop; j++) {
        s[j] = ' ';
    }

    if (remains > 0) {
        s[j] = ' ';
    }
}

int main(void) {
    int k;
    scanf("%d\n", &k);

    char s[LEN + 2];
    fgets(s, LEN + 2, stdin);

    int len_s = strlen(s) - 1;

    int dif = k - len_s;
    int cnt_space = 0;

    for (int i = 0; i < len_s; i++) {
        if (s[i] == ' ') {
            cnt_space++;
        }
    }

    int equal = dif / cnt_space;

    int remains = dif % cnt_space;
    char ans[k + 1];

    ans[k] = '\0';

    int j = 0;

    for (int i = 0; i < len_s; i++) {
        ans[j] = s[i];

        if (s[i] == ' ') {
            j++;
            insert_space(ans, equal, remains, j);

            if (remains > 0) {
                j += equal + 1;
            } else {
                j += equal;
            }

            remains--;
        } else {
            j++;
        }
    }

    fputs(ans, stdout);

    return 0;
}