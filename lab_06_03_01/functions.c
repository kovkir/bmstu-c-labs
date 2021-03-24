#include <stdio.h>
#include <string.h>
#include "functions.h"

int read_max_price(const char *string, int *max_price)
{
    *max_price = 0;
    
    while (*string != '\0' && *string - '0' >= 0 && *string - '0' <= 9)
    {
        *max_price = *max_price * 10 + *string - '0';
        string++;
    }
    
    if (*max_price == 0 || *(--string) - '0' < 0 || *(--string) - '0' > 9)
    {
        return INCORRECT_PRICE_ENTRY;
    }
    
    return OK;
}

int read_the_number_of_products(FILE *f, int *number_of_products)
{
    int r;
    
    r = fscanf(f, "%d", number_of_products);
        
    if (r != 1)
    {
        return NUMBER_OF_PRODUCTS_UNKNOWN;
    }
    else if (*number_of_products < 0 || *number_of_products >
        MAXIMUM_NUMBER_OF_PRODUCTS)
    {
        return IMPOSSIBLE_NUMBER_OF_PRODUCTS;
    }
    
    char symbol;
    
    r = fscanf(f, "%c", &symbol);
        
    if (r == 1 && symbol != '\n')
    {
        return NUMBER_OF_PRODUCTS_UNKNOWN;
    }
    
    return OK;
}

int read_information_into_an_array(FILE *f, product array[],
const int number_of_products)
{
    int r, i;
    char symbol;

    for (i = 0; getc(f) != EOF; i++)
    {
        if (fseek(f, -1, SEEK_CUR))
        {
            return FAILED_TO_READ_PRODUCT_NAME;
        }
        else if (i == number_of_products)
        {
            return FILE_IS_FULL;
        }
        else if (fgets(array[i].product_name, MAX_PRODUCT_NAME_LENGTH + 2, f)
            == NULL)
        {
            return FAILED_TO_READ_PRODUCT_NAME;
        }
        else if (strlen(array[i].product_name) == MAX_PRODUCT_NAME_LENGTH + 1 &&
            array[i].product_name[MAX_PRODUCT_NAME_LENGTH] != '\n')
        {
            return EXCEEDED_MAXIMUM_LENGTH_PRODUCT_NAME;
        }
        else if (strlen(array[i].product_name) == 1 &&
            array[i].product_name[0] == '\n')
        {
            return EMPTY_LINE;
        }
        
        r = fscanf(f, "%d", &array[i].product_price);

        if (r != 1 || array[i].product_price <= 0)
        {
            return FAILED_TO_READ_PRODUCT_PRICE;
        }
        
        r = fscanf(f, "%c", &symbol);
        
        if (r == 1 && symbol != '\n')
        {
            return FAILED_TO_READ_PRODUCT_PRICE;
        }
    }
    
    if (i < number_of_products - 1)
    {
        return FILE_IS_NOT_FULL;
    }
    
    return OK;
}

void printing_the_necessary_goods(product array[], 
const int number_of_products, const int max_price)
{
    for (int i = 0; i < number_of_products; i++)
    {
        if (array[i].product_price < max_price)
        {
            printf("%s%d\n", array[i].product_name,
            array[i].product_price);
        }
    }
}
