#ifndef FILTER_H
#define FILTER_H

#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "errors.h"
#include "free.h"

void shift_of_array_elem_to_right(product array[], int end_index);

int filter(product **array, int *const number_of_products, const int max_price);

#endif