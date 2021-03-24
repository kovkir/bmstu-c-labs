#include "../inc/read_print.h"

char *buf = NULL;
size_t size_buf = 1;

int read_max_price(const char *string, int *max_price)
{
    *max_price = 0;
    
    while (*string != '\0' && *string - '0' >= 0 && *string - '0' <= 9)
    {
        *max_price = *max_price * 10 + *string - '0';
        string++;
    }
    
    if (*max_price == 0 || *(--string) - '0' < 0 || *string - '0' > 9)
    {
        return INCORRECT_PRICE_ENTRY;
    }
    
    return SUCCESS;
}

int read_number_of_products(FILE *f, int *number_of_products)
{
    int r;
    
    r = fscanf(f, "%d", number_of_products);
        
    if (r != 1)
    {
        return NUMBER_OF_PRODUCTS_UNKNOWN;
    }
    else if (*number_of_products <= 0)
    {
        return IMPOSSIBLE_NUMBER_OF_PRODUCTS;
    }
    
    char symbol;
    
    r = fscanf(f, "%c", &symbol);
        
    if (r == 1 && symbol != '\n')
    {
        return NUMBER_OF_PRODUCTS_UNKNOWN;
    }
    
    return SUCCESS;
}

int read_product_name(product *product, FILE *f)
{
    size_t current_size = 0;

    char symbol, *p;
    int i = 0;

    while ((symbol = getc(f)) != '\n')
    {
        if (size_buf - current_size - sizeof(char) <= 0)
        {
            p = realloc(buf, size_buf *= 2);

            if (!p)
                return MEMORY_ALIGNMENT_ERROR;

            buf = p;
        }

        current_size += sizeof(char);
        buf[i++] = symbol;
    }

    if (!i)
        return EMPTY_LINE;

    current_size++;
    buf[i] = '\0';

    product->product_name = malloc(current_size * sizeof(char));

    if (!product->product_name)
        return MEMORY_ALIGNMENT_ERROR;

    strncpy(product->product_name, buf, current_size);

    return SUCCESS;
}

int read_product_price(int *product_price, FILE *f)
{
    char symbol;

    int r = fscanf(f, "%d", product_price);

    if (r != 1 || *product_price <= 0)
    {
        return FAILED_TO_READ_PRODUCT_PRICE;
    }
        
    r = fscanf(f, "%c", &symbol);
        
    if (r == 1 && symbol != '\n')
    {
        return FAILED_TO_READ_PRODUCT_PRICE;
    }

    return SUCCESS;
}

int read_information_into_an_array(FILE *f, product array[],
const int number_of_products)
{
    int r, i;

    for (i = 0; getc(f) != EOF; i++)
    {
        if (fseek(f, -1, SEEK_CUR))
        {
            free_array(array, number_of_products);
            return FAILED_TO_READ_PRODUCT_NAME;
        }
        else if (i == number_of_products)
        {
            free_array(array, number_of_products);
            return FILE_IS_FULL;
        }

        r = read_product_name(array + i, f);

        if (r)
        {
            free_array(array, number_of_products);
            return r;
        }

        r = read_product_price(&array[i].product_price, f);

        if (r)
        {
            free_array(array, number_of_products);
            return r;
        }

        LOG_DEBUG("product_name = %s, product_price = %d", 
        array[i].product_name, array[i].product_price);
    }
    
    if (i < number_of_products)
    {
        free_array(array, number_of_products);
        return FILE_IS_NOT_FULL;
    }
    
    free(buf);
    
    return SUCCESS;
}

void print_goods(product array[], const int number_of_products)
{
    for (int i = 0; i < number_of_products; i++)
    {
        printf("%s\n%d\n", array[i].product_name, array[i].product_price);
    }
}
