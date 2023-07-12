#include <stdio.h>

#define SIZE 8
#define N_CELLS (SIZE * SIZE)
#define MAX_LEN 128

int main(void) {
    int matrix[SIZE + 2][SIZE + 2] = {0};

    char str[MAX_LEN + 1];
    scanf("%128s", str);

    int i = 0;

    while (str[i] != '\0') {
        int x = str[i] - 'a' + 1;
        int y = str[i + 1] - '0';

        for (int k = -1; k <= 1; k++) {
            for (int m = -1; m <= 1; m++) {
                matrix[x + k][y + m] = 1;
            }
        }

        i += 2;
    }

    int ans = N_CELLS;

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if (matrix[i][j]) {
                ans--;
            }
        }
    }

    printf("%d", ans);

    return 0;
}