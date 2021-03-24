#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, const char *argv[])
{
    FILE *f, *f_out;
    int r;
    size_t size;
    
    if (argc == 3 && strcmp(argv[1], "sb") == 0)
    {
        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            printf("Такого файла не существует\n");
            return FILE_DOES_NOT_EXIST;
        }

        r = file_size(f, &size);

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

        sort_file(f);
        print_file(f);

        fclose(f);
    }
    else if (argc == 5 && strcmp(argv[1], "fb") == 0)
    {
        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            printf("Такого файла не существует\n");
            return FILE_DOES_NOT_EXIST;
        }

        r = file_size(f, &size);

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

        f_out = fopen(argv[3], "wb");
        r = finding_the_right_students(f, f_out, argv[4]);
        fclose(f_out);

        if (r == NEW_FILE_IS_EMPTY)
        {
            printf("Новый файл пуст\n");
            return NEW_FILE_IS_EMPTY;
        }

        fclose(f);
    }
    else if (argc == 3 && strcmp(argv[1], "db") == 0)
    {
        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            printf("Такого файла не существует\n");
            return FILE_DOES_NOT_EXIST;
        }

        r = file_size(f, &size);

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

        remove_specific_students(f, size, argv[2]);

        fclose(f);
    }
    else
    {
        printf("Неверно переданны аргументы\n");
        return INVALID_ARGUMENTS_PASSED;
    }

    return OK;
}
