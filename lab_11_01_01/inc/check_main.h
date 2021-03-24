#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>

#include "check_my_snprintf.h"

#define SUCCESS 0
#define DIFFERENT_ARRAYS 1

int compare_arrays(char *first_array, char *second_array, int size);

#endif
