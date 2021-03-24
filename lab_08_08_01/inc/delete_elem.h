#ifndef DELETE_ELEM_H
#define DELETE_ELEM_H

#include "../inc/structures.h"
#include "../inc/macrologger.h"
#include "../inc/alloc_free_memory.h"

int search_desired_row(matrix_t matrix);

void delete_row(matrix_t *const matrix, const int numb_row);

void delete_specific_rows(matrix_t *const matrix);

int search_desired_column(matrix_t matrix);

void delete_column(matrix_t *const matrix, const int numb_column);

void delete_specific_columns(matrix_t *const matrix);

void remove_desired_elements(matrix_t *const matrix);

#endif
