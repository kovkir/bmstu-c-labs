#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR 1
#define INVALID_X_VALUE 2
#define INVALID_EPS_VALUE 3

#define MINIMUM_VALUE_OF_EPS 0
#define MAXIMUM_VALUE_OF_EPS 1
#define MAXIMUM_VALUE_OF_X 1

int checking_the_number_n(double x, double eps)
{
    if (fabs(x) >= MAXIMUM_VALUE_OF_X)
    {
        printf("Неверное значение x!\n");
        return INVALID_X_VALUE;
    }
    else if ((eps <= MINIMUM_VALUE_OF_EPS) || (eps >= MAXIMUM_VALUE_OF_EPS))
    {
        printf("Неверное значение eps!\n");
        return INVALID_EPS_VALUE;
    }
    else
        return OK;
}

double function_value(double eps, double x)
{
    double sx, elem, chisl, znam;
    int n, correct_input;
    
    correct_input = checking_the_number_n(x, eps);
    
    if (correct_input == INVALID_X_VALUE)
        return INVALID_X_VALUE;
    else if (correct_input == INVALID_EPS_VALUE)
        return INVALID_EPS_VALUE;
    
    n = 1;
    sx = 0;
    elem = x;
    chisl = 1;
    znam = 1;
    
    while (fabs(elem) > eps)
    {
        sx += elem;
        chisl *= n * n;
        n += 2;
        znam *= n * (n - 1);
        elem = pow(x, n) * chisl / znam;
    }
    return sx;
}

int main(void)
{
    double x, eps, sx, fx, abs_oshib, otn_oshib;
    int r;
    
    printf("Введите x и eps: \n");
    r = scanf("%lf %lf", &x, &eps);
    
    if (r != 2)
    {
        printf("Ошибка ввода!\n");
        return INPUT_ERROR;
    }
    
    sx = function_value(eps, x);
    
    if ((int) sx == INVALID_X_VALUE)
        return INVALID_X_VALUE;
    else if ((int) sx == INVALID_EPS_VALUE)
        return INVALID_EPS_VALUE;
    
    fx = asin(x);
    abs_oshib = fabs(fx - sx);
    otn_oshib = fabs((fx - sx) / fx);
    printf("s(x) = %.6f\nf(x) = %.6f\nабсолютная ошибка = %.6f\n\
относительная ошибка = %.6f\n", sx, fx, abs_oshib, otn_oshib);
    return OK;
}
