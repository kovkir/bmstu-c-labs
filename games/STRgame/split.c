#include <stdio.h>

int split(const char *string, char **matrix, const char symbol)
{
    int j = 0, y = 0;

    for (int i = 0; *(string + i) != '\0'; i++)
    {
        if (*(string + i) == symbol)
        {
            matrix[j][y] = '\0';
            y = 0;
            j++;
        }
        else
        {
            matrix[j][y] = *(string + i);
            y++;
        }
    }

    matrix[j][y] = '\0';
    j++;

    return j;
}
