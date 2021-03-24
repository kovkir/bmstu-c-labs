#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void create_file(const int quantity, FILE *f)
{
    int number;

    for (int i = 0; i < quantity; i++)
    {
        number = rand() % NUMBER_RANGE;
        fwrite(&number, sizeof(int), 1, f);
    }
}

int file_size(FILE *f)
{
    long int sz;
    
    if (fseek(f, 0L, SEEK_END))
    {
        return NO_FILE_SIZE;
    }
    
    sz = ftell(f);
    
    if (sz <= 0)
    {
        return NO_FILE_SIZE;
    }
    else if (sz % 4 != 0)
    {
        return WRONG_FILE_SIZE;
    }
    
    return fseek(f, 0L, SEEK_SET);
}

int get_number_by_pos(FILE *f, const int i, int *const number)
{
    long int kol = 1;
    
    fseek(f, i * sizeof(int), SEEK_SET);
    kol = fread(number, sizeof(int), kol, f);
    
    if (kol != 1)
    {
        return COULD_NOT_READ_CHARACTER;
    }

    return OK;
}

void put_number_by_pos(FILE *f, const int i, int *const number)
{
    fseek(f, i * sizeof(int), SEEK_SET);
    fwrite(number, sizeof(int), 1, f);
}

int print_file(FILE *f)
{
    int r, number;
    
    r = file_size(f);
    
    if (r == OK)
    {
        for (int i = 0; get_number_by_pos(f, i, &number) == OK; i++)
        {
            printf("%d ", number);
        }
    }
    else if (r == WRONG_FILE_SIZE)
    {
        return WRONG_FILE_SIZE;
    }
    else
    {
        return NO_FILE_SIZE;
    }
    return OK;
}

int sort_file(FILE *f, const char name_file[])
{
    int r, number, min, j_min, a, b = 0;
    
    r = file_size(f);
    
    if (r == OK)
    {
        for (int i = 0; get_number_by_pos(f, i, &number) == OK; i++)
        {
            min = number;
            j_min = i;
            
            for (int j = i; get_number_by_pos(f, j, &number) == OK; j++)
            {
                if (number < min)
                {
                    j_min = j;
                    get_number_by_pos(f, j, &min);
                }
            }

            get_number_by_pos(f, i, &a);
            get_number_by_pos(f, j_min, &b);
            put_number_by_pos(f, j_min, &a);
            put_number_by_pos(f, i, &b);
        }
    }
    else if (r == WRONG_FILE_SIZE)
    {
        return WRONG_FILE_SIZE;
    }
    else
    {
        return NO_FILE_SIZE;
    }
    return OK;
}
