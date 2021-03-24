#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include "../inc/structures.h"
#include "errors.h"
#include "../inc/alloc_free_memory.h"
#include "../inc/read_print.h"
#include "../inc/macrologger.h"

#define ELEM_OF_IDENTITY_MATRIX(i, j) i == j ? 1 : 0

void copy_matrix(int **source, int **destination, 
const int numb_rows, const int numb_columns);

int find_matrix_element(matrix_t *const matrix_a, matrix_t *const matrix_b,
const int i, const int j);

void matrix_multiplication(matrix_t *const res_matrix,
matrix_t *const matrix_a, matrix_t *const matrix_b);

void fill_identity_matrix(matrix_t *const matrix);

int prepare_matrix_for_work(matrix_t *const matrix, const int size);

int raise_matrix_to_power(matrix_t *const matrix, const int power_mat);

int raise_matrices_to_power(matrix_t *const matrix_a, matrix_t *const matrix_b);

int calculate_result_matrix(matrix_t *const matrix_res, 
matrix_t *const matrix_a, matrix_t *const matrix_b);

#endif
