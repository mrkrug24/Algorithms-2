#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void swap(char*** matrix, int a, int b) {
    char* name = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));
    char* ip = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));

    name = matrix[a][0];
    ip = matrix[a][1];

    matrix[a][0] = matrix[b][0];
    matrix[a][1] = matrix[b][1];

    matrix[b][0] = name;
    matrix[b][1] = ip;
}

int divide(char*** matrix, int first, int last) {
    char* name = matrix[last][0];
    int ind = first - 1;

    for (int i = first; i < last; i++) {
        if (strcmp(name, matrix[i][0]) > 0) {
            swap(matrix, ++ind, i);
        }
    }

    swap(matrix, ++ind, last);
    return ind;
}

void sort(char*** matrix, int first, int last) {
    if (first < last) {
        int middle = divide(matrix, first, last);
        sort(matrix, first, middle - 1);
        sort(matrix, middle + 1, last);
    }
}

void bin_search(char*** matrix, char* req, int left, int right, FILE* ans) {
    if (strcmp(matrix[left][0], req) == 0) {
        fprintf(ans, "%s\n", matrix[left][1]);
        return;
    }

    if (strcmp(matrix[right][0], req) == 0) {
        fprintf(ans, "%s\n", matrix[right][1]);
        return;
    }

    while (left <= right) {
        int middle = (left + right) / 2;

        if (strcmp(matrix[middle][0], req) == 0) {
            fprintf(ans, "%s\n", matrix[middle][1]);
            return;
        }

        if (strcmp(req, matrix[middle][0]) < 0) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    fprintf(ans, "-1\n");
    return;
}

int main(void) {
    char filename[] = "input.txt";
    FILE *fp;
    fp = fopen(filename, "r");

    int n;
    fscanf(fp, "%d\n", &n);

    char*** matrix = (char***)malloc(sizeof(char**) * n);

    for (int i = 0; i < n; i++) {
        char* name = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));
        char* ip = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));
        fscanf(fp, "%s %s\n", name, ip);

        matrix[i] = (char**)malloc(2 * sizeof(MAX_SIZE + 1));
        matrix[i][0] = name;
        matrix[i][1] = ip;
    }

    sort(matrix, 0, n - 1);

    int m;
    fscanf(fp, "%d\n", &m);

    char output[] = "output.txt";
    FILE *ans;
    ans = fopen(output, "w");

    for (int i = 0; i < m; i++) {
        char* request = (char*)malloc(sizeof(char) * (MAX_SIZE + 1));
        fscanf(fp, "%s\n", request);
        bin_search(matrix, request, 0, n - 1, ans);
        free(request);
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i][0]);
        free(matrix[i][1]);
        free(matrix[i]);
    }

    free(matrix);

    fclose(fp);
    fclose(ans);

    return 0;
}