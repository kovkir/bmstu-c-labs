#ifndef CHECK_SORT_H
#define CHECK_SORT_H

#include <check.h>

#include "check_main.h"
#include "sort.h"
#include "errors.h"

void sort_check(int *array1, const int len1, int *array2, const int len2);

Suite *sort_suite(Suite *s);

#endif
