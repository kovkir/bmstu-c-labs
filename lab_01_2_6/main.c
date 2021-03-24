#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR 1
#define TRIANGLE_DOES_NOT_EXIST 2
#define O 1e-6

int triangle_check(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double ab, bc, ac;
    ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    ac = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    
    if (ac >= ab + bc || bc >= ab + ac || ab >= bc + ac)
    {
        printf("Треугольника с такими вершинами не существует!\n");
        return TRIANGLE_DOES_NOT_EXIST;
    }
    else
        return OK;
}

void location_of_a_point(double x1, double y1, double x2,
double y2, double x3, double y3, double xa, double ya)
{
    double a1, a2, a3;
    
    a1 = (x1 - xa) * (y2 - y1) - (x2 - x1) * (y1 - ya);
    a2 = (x2 - xa) * (y3 - y2) - (x3 - x2) * (y2 - ya);
    a3 = (x3 - xa) * (y1 - y3) - (x1 - x3) * (y3 - ya);
    
    if ((a1 > 0 && a2 > 0 && a3 > 0) || (a1 < 0 && a2 < 0 && a3 < 0))
        printf("Точка с введёнными координатами лежит внутри треугольника: 0\n");
    else if ((fabs(a1) < O || fabs(a2) < O || fabs(a3) < O) && ((a1 >= 0 && a2 >= 0 &&
        a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0)))
        printf("Точка с введёнными координатами лежит на границе треугольника: 1\n");
    else
        printf("Точка с введёнными координатами лежит вне треугольника: 2\n");
}

int main(void)
{
    int r, correct_input;
    double x1, y1, x2, y2, x3, y3, xa, ya;
    printf("Введите координаты вершин треугольника и точки: \n");
    r = scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &xa, &ya);
    
    if (r != 8)
    {
        printf("Ошибка ввода!\n");
        return INPUT_ERROR;
    }
    correct_input = triangle_check(x1, y1, x2, y2, x3, y3);
    
    if (correct_input == TRIANGLE_DOES_NOT_EXIST)
        return TRIANGLE_DOES_NOT_EXIST;
    
    location_of_a_point(x1, y1, x2, y2, x3, y3, xa, ya);
    
    return OK;
}
