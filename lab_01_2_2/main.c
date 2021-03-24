#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    float x1, y1, x2, y2, x3, y3, ab, bc, ac, p;
    printf("Введите координаты вершин треугольника: \n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    ac = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    p = ab + bc + ac;
    printf("Периметр треугольника равен %.5f\n", p);
    return OK;
}
