#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *myfile;
    myfile = fopen("input.txt", "r");

    int n, m;
    fscanf(myfile, "%d %d", &n, &m);

    int shift = 0;

    for (int i = 0; i < m; i++) {
        fscanf(myfile, "%d", &shift);
    }

    FILE *ans;
    ans = fopen("output.txt", "w");

    for (int i = shift; i <= n; i++) {
        fprintf(ans, "%d ", i);
    }

    for (int i = 1; i < shift; i++) {
        fprintf(ans, "%d ", i);
    }

    fclose(myfile);
    fclose(ans);

    return 0;
}