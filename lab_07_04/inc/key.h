#ifndef KEY_H
#define KEY_H

#include <stdlib.h>

#include "errors.h"
#include "macrologger.h"

double find_arithmetic_mean(const int *const begin, const int *const end);

int find_number_required_elements(const int *const begin, const int *const end,
const double average);

void fill_a_new_array(const int *begin, const int *end,
int **begin_fa, int **end_fa, const double average);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
