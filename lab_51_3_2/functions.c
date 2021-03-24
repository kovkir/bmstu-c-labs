#include <stdio.h>
#include <math.h>
#include "functions.h"

int find_avg(FILE *f, float *const avg, int *const quantity)
{
    float number;
    
    while (fscanf(f, "%f", &number) == 1)
    {
        *avg += number;
        (*quantity)++;
    }
    
    if (*quantity == 0)
    {
        return NO_NUMBER_FOUND;
    }

    *avg /= *quantity;

    return OK;
}

int find_disp(FILE *f, const float avg, float disp, const int quantity)
{
    float number;
    
    while (fscanf(f, "%f", &number) == 1)
    {
        disp += pow(number - avg, 2);
    }
    
    disp /= quantity;
    
    return disp;
}

void checking_three_sigma_rule(FILE *f, const float avg, const float sigm)
{
    float number;
    int k = 1;
    
    while (fscanf(f, "%f", &number) == 1)
    {
        if (number <= avg - 3 * sigm && number >= avg + 3 * sigm)
        {
            k = 0;
            break;
        }
    }
    
    printf("%d\n", k);
}
