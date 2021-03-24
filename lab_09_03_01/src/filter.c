#include "../inc/filter.h"

void shift_of_array_elem_to_right(product array[], int end_index)
{
    for (int i = end_index; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
}

int filter(product **array, int *const number_of_products, const int max_price)
{
    product goods;
    int quant_req_goods = 0;

    for (int i = *number_of_products - 1; i >= quant_req_goods; i--)
    {
        if ((*array)[i].product_price < max_price)
        {
            goods = (*array)[i];

            shift_of_array_elem_to_right(*array, i);
            (*array)[0] = goods;

            quant_req_goods++;
            i++;
        }
        else
        {
            free((*array)[i].product_name);
            (*number_of_products)--;
        }
    }

    if (*number_of_products == 0)
    {
        free_array(*array, *number_of_products);
        *array = NULL;

        return SUCCESS;
    }

    product *p = realloc(*array, *number_of_products * sizeof(product));

    if (!p)
        return MEMORY_ALIGNMENT_ERROR;
 
    *array = p;

    return SUCCESS;
}
