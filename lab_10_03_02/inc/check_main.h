#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>

#include "errors.h"
#include "structures.h"

#include "check_mul.h"
#include "check_sqr.h"
#include "check_div.h"

int comparing_list_to_array(node_t *head, int *array, int size);

#endif
