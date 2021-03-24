#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAXIMUM_NUMBER_OF_PRODUCTS 15
#define MAX_PRODUCT_NAME_LENGTH 25

#define OK 0
#define ARGUMENTS_PASSED_INCORRECTLY 1
#define FILE_DOES_NOT_EXIST 2
#define NUMBER_OF_PRODUCTS_UNKNOWN 3
#define IMPOSSIBLE_NUMBER_OF_PRODUCTS 4
#define FAILED_TO_READ_PRODUCT_NAME 5
#define EXCEEDED_MAXIMUM_LENGTH_PRODUCT_NAME 6
#define EMPTY_LINE 7
#define FAILED_TO_READ_PRODUCT_PRICE 8
#define INCORRECT_PRICE_ENTRY 9
#define FILE_IS_FULL 10
#define FILE_IS_NOT_FULL 11
#define COULD_NOT_CLOSE_FILE 12

typedef struct
{
    char product_name[MAX_PRODUCT_NAME_LENGTH + 2];
    int product_price;
} product;

int read_max_price(const char *string, int *max_price);
int read_the_number_of_products(FILE *f, int *number_of_products); 
int read_information_into_an_array(FILE *f, product array[],
const int number_of_products);
void printing_the_necessary_goods(product array[],
const int number_of_products, const int max_price);

#endif
