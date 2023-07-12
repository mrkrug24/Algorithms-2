#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_digit(char c) {
    int x = (int) c - '0';

    if (x >= 0 && x <= 9) {
        return x;
    } else {
        return -1;
    }
}

char check_op(char c) {
    if (c == '+') {
        return '+';
    }

    if (c == '-') {
        return '-';
    }

    return 0;
}

void make_op(char c, long long x, long long* ans) {
    if (c == '+') {
        *ans += x;
    } else {
        *ans -= x;
    }
}

int main(void) {
    FILE *myfile;
    myfile = fopen("input.txt", "r");

    char element = fgetc(myfile);

    long long ans = 0;
    long long number = 0;

    char op;

    if (check_op(element) != 0) {
        op = element;
        element = fgetc(myfile);
    } else {
        op = '+';
    }

    while (check_digit(element) == -1) {
        element = fgetc(myfile);
    }

    long long first = 0;

    while (check_digit(element) != -1) {
        first *= 10;
        first += check_digit(element);
        element = fgetc(myfile);
    }

    make_op(op, first, &ans);
    op = 0;

    while (element != '\n') {
        op = check_op(element);

        while (op == 0) {
            element = fgetc(myfile);
            op = check_op(element);
        }

        while (check_digit(element) == -1) {
            element = fgetc(myfile);
        }

        while (check_digit(element) != -1) {
            number *= 10;
            number += check_digit(element);
            element = fgetc(myfile);
        }

        make_op(op, number, &ans);
        op = 0;
        number = 0;
    }

    FILE *res;
    res = fopen("output.txt", "w");
    fprintf(res, "%lld ", ans);

    fclose(myfile);
    fclose(res);


    return 0;
}