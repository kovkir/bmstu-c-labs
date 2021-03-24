#ifndef READ_PRINT_H
#define READ_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "structures.h"
#include "free.h"
#include "macrologger.h"

int read_max_price(const char *string, int *max_price);

int read_number_of_products(FILE *f, int *number_of_products); 

int read_product_name(product *product, FILE *f);

int read_product_price(int *product_price, FILE *f);

int read_information_into_an_array(FILE *f, product array[],
const int number_of_products);

void print_goods(product array[], const int number_of_products);

#endif
