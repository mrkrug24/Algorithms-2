#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char filename[] = "matrix.in";
    FILE *fp;
    fp = fopen(filename, "rb");

    unsigned char a, b;
    fread(&a, sizeof(char), 1, fp);
    fread(&b, sizeof(char), 1, fp);

    unsigned int x = a << 8;
    unsigned int y = b;

    int n = x + y;
    unsigned long long trace = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            unsigned char first, second, third, fourth;
            fread(&first, sizeof(char), 1, fp);
            fread(&second, sizeof(char), 1, fp);
            fread(&third, sizeof(char), 1, fp);
            fread(&fourth, sizeof(char), 1, fp);

            if (i == j) {
                unsigned int a = first;
                unsigned int b = second;
                unsigned int c = third;
                unsigned int d = fourth;

                a <<= 24;
                b <<= 16;
                c <<= 8;

                int elem = a + b + c + d;
                trace += elem;
            }
        }
    }

    char output[] = "trace.out";
    FILE *ans;
    ans = fopen(output, "wb");

    for (int i = 7; i >= 0; i--) {
        unsigned long long tmp = trace;
        tmp >>= (8 * i);
        unsigned char add = tmp;

		fwrite(&add, sizeof(char), 1, ans);
	}

    fclose(fp);
    fclose(ans);

    return 0;
}