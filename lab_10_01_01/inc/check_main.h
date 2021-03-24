#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>

#include "errors.h"
#include "structures.h"
#include "check_sort.h"
#include "check_reverse.h"
#include "check_pop_front.h"

int comparing_list_to_array(node_t *head, int *array[], int size);

#endif
