#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>

#include "errors.h"
#include "structures.h"
#include "check_read.h"

int compare_arrays(product *array, const int numb_of_prod, 
product *res_array, const int res_numb_of_prod);

#endif