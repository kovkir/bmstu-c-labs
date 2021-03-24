#include "my_strchr.h"
#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define ERROR_IN_MY_FUNCTION 1

int print_result(char *lib_p, char *my_p, char symbol)
{
    if (lib_p == my_p)
        printf("Для символа '%c'\n\
strchr    выдаст %p\nmy_strchr выдаст %p\n\n", symbol, lib_p, my_p);
    else
    {
        printf("Для символа '%c'\nМоя функция работает некоректно\n", symbol);
        return ERROR_IN_MY_FUNCTION;
    }
    
    return SUCCESS;
}

int main(void)
{
    char str[] = "abc0 0123qwerty";
    char *lib_p, *my_p;
    int symbol[] = { ' ', '0', 'k', 'y', '\0' }, k;
    
    for (int i = 0; i < sizeof(symbol) / sizeof(symbol[0]); i++)
    {
        lib_p = strchr(str, symbol[i]);
        my_p = my_strchr(str, symbol[i]);

        k = print_result(lib_p, my_p, symbol[i]);
        
        if (k == ERROR_IN_MY_FUNCTION)
            return ERROR_IN_MY_FUNCTION;
    }
    
    printf("Две функции выдают одинаковый результат!\n");
    
    return SUCCESS;
}
