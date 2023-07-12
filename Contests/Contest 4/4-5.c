#include <stdio.h>
#include <string.h>

#define N 2000
#define MAX 120000

int check_digit(char c) {
    int x = (int) c - '0';

    if (x >= 0 && x <= 9) {
        return x;
    } else {
        return -1;
    }
}

char check_op(char c) {
    if (c == '*') {
        return '*';
    }

    if (c == '+') {
        return '+';
    }

    if (c == '-') {
        return '-';
    }

    if (c == '/') {
        return '/';
    }

    return 0;
}

void operation(int a, int b, char c) {
    if (c == '+' && a + b <= MAX) {
        printf("%d + %d = %d \n", a, b, a + b);
    }

    if (c == '-' && a - b <= MAX) {
        printf("%d - %d = %d \n", a, b, a - b);
    }

    if (c == '*' && a * b <= MAX) {
        printf("%d * %d = %d \n", a, b, a * b);
    }

    if (c == '/' && b != 0 && a / b <= MAX) {
        printf("%d / %d = %d \n", a, b, a / b);
    }
}

int exponent(int a, int n) {
    int ans = 1;

    for (int i = 0; i < n; i++) {
        ans *= a;
    }

    return ans;
}

int main(void) {
    char s[N + 1];
    scanf("%2000s", s);

    int len_s = strlen(s);

    for (int i = 0; i < len_s; i++) {
        int first = -1;
        int second = -1;
        int offset = 1;
        char op = check_op(s[i]);

        if (op != 0) {
            while (check_digit(s[i - offset]) != -1 && i - offset >= 0) {
                int x = check_digit(s[i - offset]);

                if (first == -1) {
                    first = x;
                } else {
                    first += x * exponent(10, offset - 1);
                }

                offset++;
            }

            offset = 1;

            while (check_digit(s[i + offset]) != -1 && i + offset < len_s) {
                int x = check_digit(s[i + offset]);

                if (second == -1) {
                    second = x;
                } else {
                    second *= 10;
                    second += x;
                }

                offset++;
            }

            if (first != -1 && second != -1) {
                operation(first, second, op);
            }
        }
    }

    return 0;
}