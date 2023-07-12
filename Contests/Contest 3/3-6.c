#include <stdio.h>
#include <stdlib.h>

#define N 8

int queen(int x_start, int y_start, int x, int y) {
    return abs(x - x_start) * abs(y - y_start) == 2;
}

int knight(int x_start, int y_start, int x, int y) {
    if (x_start == x && y_start == y) {
        return 0;
    }

    if (x_start == x || y_start == y) {
        return 1;
    }

    if (abs(x - x_start) == abs(y - y_start)) {
        return 1;
    }

    return 0;
}


int main(void) {
    int x_start = 1;
    int y_start = 1;
    int gamer = 0;
    int h8 = 0;

    char str[2];
    int ans = 1;

    int move = 1;

    while (move) {
        scanf("%2s", str);

        if (str[0] == 'X') {
            move = 0;
        }

        int x = str[0] - 'A' + 1;
        int y = str[1] - '0';

        if (str[0] == 'X') {
            break;
        }

        if (x == N && y == N) {
            h8++;
        }

        if (gamer == 0) {
            if (queen(x_start, y_start, x, y) == 0) {
                ans = 0;
            }
        } else {
            if (knight(x_start, y_start, x, y) == 0) {
                ans = 0;
            }
        }

        gamer = !gamer;
        x_start = x;
        y_start = y;
    }

    if (ans == 1 && h8 == 1) {
        if (gamer == 0) {
            printf("Tolik");
        } else {
            printf("Garik");
        }
    } else {
        printf("Cheaters");
    }

    return 0;
}