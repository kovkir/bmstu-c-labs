#ifndef ADD_ELEM_H
#define ADD_ELEM_H

#include <math.h>

#include "../inc/macrologger.h"
#include "../inc/structures.h"
#include "errors.h"
#include "../inc/alloc_free_memory.h"

#define MIN(a, b) a < b ? a : b

int geometric_mean(matrix_t *const matrix, const int j);

int add_row(matrix_t *const matrix);

int add_column(matrix_t *const matrix);

int change_matrix(matrix_t *const matrix, const int new_size);

int add_row_columns_to_matrices(matrix_t *const matrix_a, matrix_t *const matrix_b);

#endif
