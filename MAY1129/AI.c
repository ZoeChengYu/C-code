#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x, double a) {
    double val = a - x * x;
    return val < 0 ? 0 : sqrt(val);
}

double f2(double x, double a) {
    double denom = a + x;
    if (denom <= 0) return 0;
    return (a * x * x * x + 7 * x) / sqrt(denom);
}

double trapezoidal(double (*f)(double, double), double a, double p, double q, int err) {
    int n = 1;
    double h = q - p;
    double prev = h * (f(p, a) + f(q, a)) / 2.0;
    double eps = pow(10.0, -err);

    while (1) {
        n *= 2;
        h = (q - p) / n;
        double sum = 0.0;

        for (int i = 1; i < n; i += 2) {
            double x = p + i * h;
            sum += f(x, a);
        }

        double curr = prev / 2.0 + h * sum;
        if (fabs(curr - prev) < eps) break;
        prev = curr;
    }

    return prev;
}

int main() {
    int type;
    while (scanf("%d", &type) == 1) {
        if (type == 0) break;

        double a, p, q;
        int err;
        if (scanf("%lf %lf %lf %d", &a, &p, &q, &err) != 4) {
            printf("Invalid\n");
            continue;
        }

        double (*func)(double, double) = NULL;
        if (type == 1) func = f1;
        else if (type == 2) func = f2;
        else {
            printf("Invalid\n");
            continue;
        }

        double result = trapezoidal(func, a, p, q, err);
        printf("%.12lf\n", result);
    }

    return 0;
}
