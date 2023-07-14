#include <stdio.h>
#include <stdlib.h>

// malloc = memory allocation
// realloc = re-allocation
// free (освобождение памяти)

void print_matrix(int** x, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", x[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int m = 5, n = 3;
    int** x = (int**)malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i++) {
        x[i] = (int*)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++) {
            x[i][j] = 10 * i + j;
        }
    }

    printf("Before:\n");
    print_matrix(x, m, n);
    printf("\n");

    int size = (m > n) ? m : n; // size = 5

    // RESIZE 1
    if (m < size) {
        // УВЕЛИЧЕНИЕ КОЛ-ВА СТРОК МАТРИЦЫ
        x = (int**)realloc(x, sizeof(int*) * size); // 5 x 5

        for (int i = m; i < size; i++) {
            x[i] = (int*)malloc(sizeof(int) * n);   // в каждой из добавленной снизу строки будет n элементов

            for (int j = 0; j < n; j++) {
                x[i][j] = j;
            }
        }
    } else {
        // РАСШИРЕНИЕ КАЖДОГО СТОЛБЦА МАТРИЦЫ ПРИ ТОМ ЖЕ КОЛ-ВЕ СТРОК
        for (int i = 0; i < m; i++) {
            x[i] = (int*)realloc(x[i], sizeof(int) * size); // В КАЖДОЙ СТРОКЕ БУДЕТ size ЭЛЕМЕНТОВ
        }
    }

    printf("After realloc_1 (squared matrix):\n");
    print_matrix(x, size, size);
    printf("\n");

    // ТРАНСПОНИРОВАНИЕ
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // x[i][j] <-> x[j][i]
            int tmp = x[i][j];
            x[i][j] = x[j][i];
            x[j][i] = tmp;
        }
    }

    printf("After transpose (squared matrix):\n");
    print_matrix(x, size, size);
    printf("\n");

    // RESIZE 2
    int tmp = m;
    m = n;
    n = tmp;

    if (n < size) {
        for (int i = 0; i < m; i++) {
            x[i] = (int*)realloc(x[i], sizeof(int) * n);
        }
    } else if (m < size) {
        // УДАЛЕНИЕ ЛИШНИХ СТРОК СНИЗУ
        for (int i = m; i < size; i++) {
            free(x[i]); // УДАЛЕНИЕ КАЖДОЙ ЛИШНЕЙ СТРОКИ
        }

        x = (int**)realloc(x, sizeof(int*) * m);    // МАТРИЦА ЕСТЬ УКАЗАТЕЛЬ НА m УКАЗАТЕЛЕЙ (строк)
    }

    printf("After realloc_2:\n");
    print_matrix(x, m, n);
   
    for (int i = 0; i < m; i++) {
        free(x[i]); // освобождаем память под каждую строку
    }

    free(x);        // освобождаем память под массив указателей на строки

    return 0;
}