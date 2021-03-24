#include "../inc/read_print.h"

int read_numb_rows_columns_matrix(int *const numb_rows, int *const numb_columns)
{
    int r;

    r = scanf("%d", numb_rows);

    if (r != 1)
        return ROW_LENGTH_ERROR; 

    if (*numb_rows <= 0)
        return NEGATIVE_ROW_LENGTH; 

    r = scanf("%d", numb_columns); 

    if (r != 1)
        return COLUMN_LENGTH_ERROR; 

    if (*numb_columns <= 0)
        return NEGATIVE_COLUMNS_LENGTH;

    return SUCCESS;
}

int read_matrix(matrix_t *const matrix)
{
    matrix->matrix = allocate_matrix(matrix->numb_rows, matrix->numb_columns);

    if (!(matrix->matrix))
        return FAILED_TO_ALLOCATE_MEMORY; 

    int r;

    for (int i = 0; i < matrix->numb_rows; i++) 
    {
        for (int j = 0; j < matrix->numb_columns; j++) 
        {
            r = scanf("%d", (matrix->matrix)[i] + j);

            if (r != 1)
            {
                free_matrix(matrix->matrix, matrix->numb_rows);
                return MATRIX_READ_ERROR;
            }
        }
    }

    return SUCCESS;
}

int read_matrices(matrix_t *const matrix_a, matrix_t *const matrix_b) 
{
    int r;

    r = read_numb_rows_columns_matrix(&(matrix_a->numb_rows), &(matrix_a->numb_columns));

    if (r)
        return r;

    LOG_DEBUG("numb_rows A = %d", matrix_a->numb_rows);
    LOG_DEBUG("numb_columns A = %d", matrix_a->numb_columns);

    r = read_matrix(matrix_a);

    if (r)
        return r;

    r = read_numb_rows_columns_matrix(&(matrix_b->numb_rows), &(matrix_b->numb_columns));

    if (r)
    {
        free_matrix(matrix_a->matrix, matrix_a->numb_rows);
        return r;
    }

    LOG_DEBUG("numb_rows B = %d", matrix_b->numb_rows);
    LOG_DEBUG("numb_columns B = %d", matrix_b->numb_columns);

    r = read_matrix(matrix_b);

    if (r)
    {
        free_matrix(matrix_a->matrix, matrix_a->numb_rows);
        return r;
    }

    return SUCCESS;  
}

void print_matrix(matrix_t *const matrix)
{
    printf("\n");
    for (int i = 0; i < matrix->numb_rows; i++) 
    {
        for (int j = 0; j < matrix->numb_columns; j++) 
        {
            printf("%d ", (matrix->matrix)[i][j]);
        }

        printf("\n");
    }
}

int read_degrees_of_matrices(int *const power_mat_a, int *const power_mat_b)
{
    int r;

    r = scanf("%d", power_mat_a);

    if (r != 1)
        return POWER_MATRIX_A_ERROR; 

    if (*power_mat_a < 0)
        return NEGATIVE_POWER_MATRIX_A; 

    r = scanf("%d", power_mat_b); 

    if (r != 1)
        return POWER_MATRIX_B_ERROR; 

    if (*power_mat_b < 0)
        return NEGATIVE_POWER_MATRIX_B;

    return SUCCESS;
}
