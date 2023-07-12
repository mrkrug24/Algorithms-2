#include <stdio.h>
#include <math.h>

double sqr(double x) {
    return x * x;
}

void coord(double ab, double bc, double a_x, double a_y, double c_x, double c_y) {
    double k = ab / bc;

    double ans_x = (a_x + k * c_x) / (1 + k);
    double ans_y = (a_y + k * c_y) / (1 + k);

    printf("%.5lf %.5lf \n", ans_x, ans_y);
}

double length(double a_x, double b_x, double a_y, double b_y) {
    return sqrt(sqr(a_x - b_x) + sqr(a_y - b_y));
}

int main(void) {
    double a_x, a_y, b_x, b_y, c_x, c_y;
    scanf("%lf %lf %lf %lf %lf %lf", &a_x, &a_y, &b_x, &b_y, &c_x, &c_y);

    double ab = length(a_x, b_x, a_y, b_y);
    double bc = length(c_x, b_x, c_y, b_y);
    double ac = length(a_x, c_x, a_y, c_y);

    coord(ac, bc, a_x, a_y, b_x, b_y);
    coord(ab, ac, b_x, b_y, c_x, c_y);
    coord(ab, bc, a_x, a_y, c_x, c_y);

    return 0;
}