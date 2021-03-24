#include "../inc/free.h"

void free_array(product *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(data[i].product_name);
    }

    free(data);
}
