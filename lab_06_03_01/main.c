#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        return ARGUMENTS_PASSED_INCORRECTLY;
    }
    
    int r, number_of_products, max_price;
    
    r = read_max_price(argv[2], &max_price);
    
    if (r == INCORRECT_PRICE_ENTRY)
    {
        return INCORRECT_PRICE_ENTRY;
    }
    
    FILE *f;
    
    f = fopen(argv[1], "r");
    
    if (f == NULL)
    {
        return FILE_DOES_NOT_EXIST;
    }
    
    r = read_the_number_of_products(f, &number_of_products);
    
    if (r != OK)
    {
        return r;
    }

    product array[MAXIMUM_NUMBER_OF_PRODUCTS];
    
    r = read_information_into_an_array(f, array, number_of_products);
    
    if (r != OK)
    {
        return r;
    }
    
    r = fclose(f);
    
    if (r == EOF)
    {
        return COULD_NOT_CLOSE_FILE;
    }
    
    printing_the_necessary_goods(array, number_of_products, max_price);

    return OK;
}
