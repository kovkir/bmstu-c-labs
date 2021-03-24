#include <stdio.h>
#include <limits.h>
#include "functions.h"

void write_to_file(FILE *f)
{
    int number;
    
    while (scanf("%d", &number) == 1)
    {
        fprintf(f, "%d\n", number);
    }
}

int min(const int distance, const int *const min_distance)
{
    if (distance < *min_distance)
    {
        return distance;
    }
    else
    {
        return *min_distance;
    }
}

int process(FILE *f, int *const min_distance)
{
    int number_1, number_2, number_3, distance = 0;
    
    fscanf(f, "%d", &number_1);
    fscanf(f, "%d", &number_2);
    
    while (fscanf(f, "%d", &number_3) == 1)
    {
        if (number_2 > number_1 && number_2 > number_3)
        {
            if (distance != 0)
            {
                *min_distance = min(distance, min_distance);
                distance = 0;
            }
            else
            {
                distance++;
            }
        }
        else if (distance != 0)
        {
            distance++;
        }
        
        number_1 = number_2;
        number_2 = number_3;
    }
    
    if (*min_distance == INT_MAX)
    {
        return NO_TWO_HIGHS;
    }
    
    return OK;
}
