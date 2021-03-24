#include "../inc/matrix_multiplication.h"

void copy_matrix(int **source, int **destination, 
const int numb_rows, const int numb_columns)
{
    for (int i = 0; i < numb_rows; i++)
        for (int j = 0; j < numb_columns; j++)
            destination[i][j] = source[i][j];
}


int find_matrix_element(matrix_t *const matrix_a, matrix_t *const matrix_b,
const int i, const int j)
{
    int new_matr_elem = 0;

    for (int u = 0; u < matrix_a->numb_columns; u++)
    {
        new_matr_elem += matrix_a->matrix[i][u] * matrix_b->matrix[u][j];
    }

    return new_matr_elem;
}

void matrix_multiplication(matrix_t *const res_matrix,
matrix_t *const matrix_a, matrix_t *const matrix_b)
{
    for (int i = 0; i < res_matrix->numb_rows; i++)
    {
        for (int j = 0; j < res_matrix->numb_columns; j++)
        {
            res_matrix->matrix[i][j] = find_matrix_element(matrix_a, matrix_b, i, j);
            LOG_DEBUG("i = %d, j = %d, res_matrix[i][j] = %d", i, j, res_matrix->matrix[i][j]);
        }
    }
}

void fill_identity_matrix(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->numb_rows; i++)
        for (int j = 0; j < matrix->numb_columns; j++)
            matrix->matrix[i][j] = ELEM_OF_IDENTITY_MATRIX(i, j);
}

int prepare_matrix_for_work(matrix_t *const matrix, const int size)
{   
    matrix->numb_rows = size;
    matrix->numb_columns = size;

    matrix->matrix = allocate_matrix(matrix->numb_rows, matrix->numb_columns);

    if (!matrix->matrix)
        return FAILED_TO_ALLOCATE_MEMORY;

    fill_identity_matrix(matrix);

    return SUCCESS;
}

int raise_matrix_to_power(matrix_t *const matrix, const int power_mat)
{
    matrix_t res_matrix;

    int r = prepare_matrix_for_work(&res_matrix, matrix->numb_rows);

    if (r)
        return r;

    matrix_t interm_res_matrix;

    r = prepare_matrix_for_work(&interm_res_matrix, matrix->numb_rows);

    if (r)
    {
        free_matrix(res_matrix.matrix, res_matrix.numb_rows);
        return r;
    }

    for (int i = 0; i < power_mat; i++)
    {
        matrix_multiplication(&res_matrix, &interm_res_matrix, matrix);
        copy_matrix(res_matrix.matrix, interm_res_matrix.matrix, res_matrix.numb_rows, 
        res_matrix.numb_columns);
    }

    copy_matrix(res_matrix.matrix, matrix->matrix, res_matrix.numb_rows, 
    res_matrix.numb_columns);

    free_matrix(res_matrix.matrix, res_matrix.numb_rows);
    free_matrix(interm_res_matrix.matrix, interm_res_matrix.numb_rows);
    

    return SUCCESS;
}

int raise_matrices_to_power(matrix_t *const matrix_a, matrix_t *const matrix_b)
{
    int power_mat_A, power_mat_B;

    int r = read_degrees_of_matrices(&power_mat_A, &power_mat_B);

    if (r)
    {
        free_matrix(matrix_a->matrix, matrix_a->numb_rows);
        free_matrix(matrix_b->matrix, matrix_b->numb_rows);
        return r;
    }

    LOG_DEBUG("power matrix A = %d", power_mat_A);
    LOG_DEBUG("power matrix B = %d", power_mat_B);

    r = raise_matrix_to_power(matrix_a, power_mat_A);

    if (r)
    {
        free_matrix(matrix_a->matrix, matrix_a->numb_rows);
        free_matrix(matrix_b->matrix, matrix_b->numb_rows);
        return r;
    }

    r = raise_matrix_to_power(matrix_b, power_mat_B);

    if (r)
    {
        free_matrix(matrix_a->matrix, matrix_a->numb_rows);
        free_matrix(matrix_b->matrix, matrix_b->numb_rows);
        return r;
    }

    return SUCCESS;
}

int calculate_result_matrix(matrix_t *const matrix_res, 
matrix_t *const matrix_a, matrix_t *const matrix_b)
{
    matrix_res->numb_rows = matrix_a->numb_rows;
    matrix_res->numb_columns = matrix_b->numb_columns;

    matrix_res->matrix = allocate_matrix(matrix_res->numb_rows, matrix_res->numb_columns);

    if (!matrix_res->matrix)
        return FAILED_TO_ALLOCATE_MEMORY;

    matrix_multiplication(matrix_res, matrix_a, matrix_b);

    return SUCCESS;
}
