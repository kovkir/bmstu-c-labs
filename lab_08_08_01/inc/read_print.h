#ifndef READ_PRINT_H
#define READ_PRINT_H

#include <stdio.h>
#include <stdlib.h>

#include "../inc/structures.h"
#include "../inc/errors.h"
#include "../inc/alloc_free_memory.h"
#include "../inc/macrologger.h"

int read_numb_rows_columns_matrix(int *const numb_rows, int *const numb_columns);

int read_matrix(matrix_t *const matrix);

int read_matrices(matrix_t *const matrix_a, matrix_t *const matrix_b);

void print_matrix(matrix_t *const matrix);

int read_degrees_of_matrices(int *const power_mat_a, int *const power_mat_b);

#endif
