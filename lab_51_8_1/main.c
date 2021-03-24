#include <stdio.h>
#include <limits.h>
#include "functions.h"

int main(void)
{
    int r, min_distance = INT_MAX;
    FILE *f;
    
    f = fopen("file.txt", "w");
    write_to_file(f);
    fclose(f);

    f = fopen("file.txt", "r");
    r = process(f, &min_distance);
    fclose(f);
    
    if (r == NO_TWO_HIGHS)
    {
        printf("На отрезке нету двух локальных максимумов\n");
        return NO_TWO_HIGHS;
    }
    
    printf("%d\n", min_distance);
    
    return OK;
}
