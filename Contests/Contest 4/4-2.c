#include <stdio.h>
#include <string.h>

#define L 80

int main(void) {
    long n;
    scanf("%ld", &n);

    char s[L + 1];
    scanf("%80s", s);

    int len_s = strlen(s);
    int shift = n % len_s;

    int j = 0;
    char ans[len_s];

    for (int i = shift; i < len_s; i++) {
        ans[j] = s[i];
        j++;
    }

    for (int i = 0; i < shift; i++) {
        ans[j] = s[i];
        j++;
    }

    ans[j] = '\0';

    printf("%s", ans);

    return 0;
}