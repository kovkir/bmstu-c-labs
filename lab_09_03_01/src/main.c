#include "../inc/main.h"

int parse_args(int argc, const char *argv[], 
const char **name_file, const char **str_max_price)
{
    if (argc != 3)
        return ARGUMENTS_PASSED_INCORRECTLY;

    *name_file = argv[1];
    *str_max_price = argv[2];

    return SUCCESS;
}

int main(int argc, const char *argv[])
{
    const char *name_file, *str_max_price;

    int r = parse_args(argc, argv, &name_file, &str_max_price);
    
    if (r)
        return r;

    int number_of_products, max_price;
    
    r = read_max_price(str_max_price, &max_price);
    
    if (r)
        return r;
    
    FILE *f;
    
    f = fopen(name_file, "r");
    
    if (!f)
        return FILE_DOES_NOT_EXIST;
    
    r = read_number_of_products(f, &number_of_products);
    
    if (r) 
        return r;

    product *array = calloc(number_of_products * sizeof(product), sizeof(product));

    if (!array)
        return MEMORY_ALIGNMENT_ERROR;
    
    r = read_information_into_an_array(f, array, number_of_products);
    
    if (r) 
        return r;
    
    if (fclose(f))
    {
        free_array(array, number_of_products);
        return COULD_NOT_CLOSE_FILE;
    }

    r = filter(&array, &number_of_products, max_price);

    if (r)
    {
        free_array(array, number_of_products);
        return r;
    }

    print_goods(array, number_of_products);

    free_array(array, number_of_products);

    return SUCCESS;
}
