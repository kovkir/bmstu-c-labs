/*
Для реализации задачи был выбран целочисленный тип int.
Сортировка по возрастанию реализовывалась методом "сортировка вставками".
*/
 
#include <stdio.h>
#include "functions.h"

int main(int argc, const char *argv[])
{
    if (((argc != 3) && !(argc == 4 && *argv[1] == 'c')) ||
        (argc == 3 && *argv[1] == 'c'))
    {
        printf("Неверно переданны аргументы\n");
        return INVALID_ARGUMENTS_PASSED;
    }

    FILE *f;
    int r;
    
    if (*argv[1] == 'c')
    {
        int quantity;
        
        sscanf(argv[2], "%d", &quantity);
        
        f = fopen(argv[3], "wb");
        create_file(quantity, f);
        fclose(f);
    }
    else if (*argv[1] == 'p')
    {
        f = fopen(argv[2], "rb");
        
        if (f == NULL)
        {
            printf("Такого файла не существует\n");
            return FILE_DOES_NOT_EXIST;
        }
        
        r = print_file(f);
        fclose(f);
        
        if (r == NO_FILE_SIZE)
        {
            printf("Не удалось определить размер файла\n");
            return NO_FILE_SIZE;
        }
        else if (r == WRONG_FILE_SIZE)
        {
            printf("Неправильный размер файла\n");
            return WRONG_FILE_SIZE;
        }
    }
    else if (*argv[1] == 's')
    {
        f = fopen(argv[2], "rb+");
        
        if (f == NULL)
        {
            printf("Такого файла не существует\n");
            return FILE_DOES_NOT_EXIST;
        }
        
        r = sort_file(f, argv[2]);
        fclose(f);
        
        if (r == NO_FILE_SIZE)
        {
            printf("Не удалось определить размер файла\n");
            return NO_FILE_SIZE;
        }
        else if (r == WRONG_FILE_SIZE)
        {
            printf("Неправильный размер файла\n");
            return WRONG_FILE_SIZE;
        }
    }
    return OK;
}
