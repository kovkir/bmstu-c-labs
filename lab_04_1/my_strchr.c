#include "my_strchr.h"
#include <stdio.h>


char *my_strchr(char *str, const int symbol)
{
    char *p;
    
    p = str;
    
    for (int i = 0; str[i] != '\0' && str[i] != symbol; i++)
        p++;
    
    if (*p == '\0' && symbol != '\0')
        p = NULL;
    
    return p;
}
