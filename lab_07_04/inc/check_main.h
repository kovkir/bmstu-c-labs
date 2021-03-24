#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include "check_key.h"
#include "check_sort.h"
#include "errors.h"

#define DIFFERENT_LENGTH_OF_ARRAYS 1
#define  ERROR_FOUND 2

int comparison_of_arrays(int *array_one, int len_one, int *array_two, int len_two);

#endif
