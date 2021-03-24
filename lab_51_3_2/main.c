#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("Нет имени файла\n");
        return NO_FILE_NAME;
    }
    
    FILE *f;
    int r, quantity = 0;
    float avg = 0, disp = 0, sigm;
    
    f = fopen(argv[1], "r");
    
    if (f == NULL)
    {
        printf("Такого файла не существует\n");
        return FILE_DOES_NOT_EXIST;
    }
    
    r = find_avg(f, &avg, &quantity);
    fclose(f);
    
    if (r == NO_NUMBER_FOUND)
    {
        printf("Цифр не найдено\n");
        return NO_NUMBER_FOUND;
    }
    
    f = fopen(argv[1], "r");
    disp = find_disp(f, avg, disp, quantity);
    fclose(f);
    
    sigm = sqrt(disp);
    
    f = fopen(argv[1], "r");
    checking_three_sigma_rule(f, avg, sigm);
    fclose(f);
    
    return OK;
}
