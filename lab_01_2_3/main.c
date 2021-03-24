#include <stdio.h>

#define OK 0

int main(void)
{
    double r, r1, r2, r3;
    printf("Введите три сопротивления: \n");
    scanf("%lf %lf %lf", &r1, &r2, &r3);
    r = 1 / (1 / r1 + 1 / r2 + 1 / r3);
    printf("Сопротивление соединения равно %.5f\n", r);
    return OK;
}
