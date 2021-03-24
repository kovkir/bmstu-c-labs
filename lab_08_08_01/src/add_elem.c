#include "../inc/add_elem.h"

int geometric_mean(matrix_t *const matrix, const int j)
{
    int prod_of_numbers = 1;
    double geom_meane;
    
    for (int i = 0; i < matrix->numb_rows - 1; i++)
    {
        prod_of_numbers *= abs(matrix->matrix[i][j]);
    }

    LOG_DEBUG("j = %d, prod_of_numbers = %d", j, prod_of_numbers);

    geom_meane = pow((double) prod_of_numbers, (double) 1 / (matrix->numb_rows - 1)); 

    LOG_DEBUG("j = %d, number elem = %d", j, matrix->numb_rows - 1);
    LOG_DEBUG("j = %d, geometric_mean = %lf", j, geom_meane);

    return (int) geom_meane;
}

int add_row(matrix_t *const matrix)
{
    int** p = realloc(matrix->matrix, ++matrix->numb_rows * sizeof(int*));

    if (!p)
    {
        free_matrix(matrix->matrix, --matrix->numb_rows);
        return FAILED_TO_ALLOCATE_MEMORY; 
    }

    matrix->matrix = p;
    matrix->matrix[matrix->numb_rows - 1] = malloc(matrix->numb_columns * sizeof(int));

    if (!(matrix->matrix[matrix->numb_rows - 1]))
    {
        free_matrix(matrix->matrix, matrix->numb_rows);
        return FAILED_TO_ALLOCATE_MEMORY; 
    }

    for(int j = 0; j < matrix->numb_columns; j++)
    {
        matrix->matrix[matrix->numb_rows - 1][j] = geometric_mean(matrix, j);
    }

    return SUCCESS;
}

int add_column(matrix_t *const matrix)
{
    int *p;
    matrix->numb_columns++;

    for (int i = 0; i < matrix->numb_rows; i++)
    {
        p = realloc(matrix->matrix[i], matrix->numb_columns * sizeof(int));

        if (!p)
        {
            free_matrix(matrix->matrix, matrix->numb_rows);
            return FAILED_TO_ALLOCATE_MEMORY; 
        }

        matrix->matrix[i] =  p;
    }

    int min_elem;

    for (int i = 0; i < matrix->numb_rows; i++)
    {
        min_elem = matrix->matrix[i][0];

        for (int j = 1; j < matrix->numb_columns - 1; j++)
        {
            min_elem = MIN(min_elem, matrix->matrix[i][j]);
        }

        LOG_DEBUG("i = %d, min_elem = %d", i, min_elem);

        matrix->matrix[i][matrix->numb_columns - 1] = min_elem;
    }

    return SUCCESS;
}

int change_matrix(matrix_t *const matrix, const int new_size)
{
    int r;

    while (matrix->numb_rows < new_size) 
    {
        r = add_row(matrix);

        if (r)
            return r;
    }

    while (matrix->numb_columns < new_size) 
    {
        r = add_column(matrix);

        if (r)
            return r;
    }

    return SUCCESS;
}

int add_row_columns_to_matrices(matrix_t *const matrix_a, matrix_t *const matrix_b)
{
    int r;

    if (matrix_a->numb_rows < matrix_b->numb_rows)
    {
        r = change_matrix(matrix_a, matrix_b->numb_rows);

        if (r)
        {
            free_matrix(matrix_b->matrix, matrix_b->numb_rows);
            return r;
        }
    }
    else if(matrix_a->numb_rows > matrix_b->numb_rows)
    {
        r = change_matrix(matrix_b, matrix_a->numb_rows);

        if (r)
        {
            free_matrix(matrix_a->matrix, matrix_a->numb_rows);
            return r;
        }
    }
    
    return SUCCESS;
}
