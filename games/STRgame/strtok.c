#include <stdio.h>

char *strtok(char *string, char const *delim)
{
    char *p = NULL;
    static char *static_str;
    int j;
    
    if (string == NULL)
    {
        if (static_str == NULL)
            return p;
        
        string = static_str;
    }
    
    while (*string != '\0')
    {
        for (j = 0; *(delim + j) != '\0'; j++)
        {
            if (*string == *(delim + j))
            {
                if (p != NULL)
                {
                    *string = '\0';
                    static_str = string + 1;
                    return p;
                }
                else
                    break;
            }
        }
        
        if (*(delim + j) == '\0' && p == NULL)
            p = string;
        
        string++;
    }
    
    static_str = NULL;
    
    return p;
}