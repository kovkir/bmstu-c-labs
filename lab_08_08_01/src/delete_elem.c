#include "../inc/delete_elem.h"

int search_desired_row(matrix_t matrix)
{
    int i_min = 0, j_min = 0;

    for (int j = 0; j < matrix.numb_columns; j++)
    {
        for (int i = 0; i < matrix.numb_rows; i++)
        {
            if (matrix.matrix[i][j] <= matrix.matrix[i_min][j_min])
            {
                i_min = i;
                j_min = j;
            }
        }
    }

    LOG_DEBUG("i_min = %d", i_min);
    LOG_DEBUG("j_min = %d", j_min);
    LOG_DEBUG("min elem in matrix = %d", matrix.matrix[i_min][j_min]);

    return i_min;
}

void delete_row(matrix_t *const matrix, const int numb_row)
{
    free(matrix->matrix[numb_row]);
    
    for (int i = numb_row; i < matrix->numb_rows - 1; i++)
    {
        matrix->matrix[i] = matrix->matrix[i + 1];
    }
}

void delete_specific_rows(matrix_t *const matrix)
{
    int numb_row;

    while (matrix->numb_rows > matrix->numb_columns)
    {
        numb_row = search_desired_row(*matrix);
        delete_row(matrix, numb_row);
        (matrix->numb_rows)--;
    }
}

int search_desired_column(matrix_t matrix)
{
    int i_min = 0, j_min = 0;

    for (int j = 0; j < matrix.numb_columns; j++)
    {
        for (int i = 0; i < matrix.numb_rows; i++)
        {
            if (matrix.matrix[i][j] <= matrix.matrix[i_min][j_min])
            {
                i_min = i;
                j_min = j;
            }
        }
    }

    LOG_DEBUG("i_min = %d", i_min);
    LOG_DEBUG("j_min = %d", j_min);
    LOG_DEBUG("min elem in matrix = %d", matrix.matrix[i_min][j_min]);

    return j_min;
}

void delete_column(matrix_t *const matrix, const int numb_column)
{
    for (int i = 0; i < matrix->numb_rows; i++)
    {
        for (int j = numb_column; j < matrix->numb_columns - 1; j++)
        {
            matrix->matrix[i][j] = matrix->matrix[i][j + 1];
        }
    }
}

void delete_specific_columns(matrix_t *const matrix)
{
    int numb_column;

    while (matrix->numb_columns > matrix->numb_rows)
    {
        numb_column = search_desired_column(*matrix);
        delete_column(matrix, numb_column);
        (matrix->numb_columns)--;
    }
}

void remove_desired_elements(matrix_t *const matrix)
{
    if (matrix->numb_rows > matrix->numb_columns)
    {
        delete_specific_rows(matrix);
    }
    else if (matrix->numb_rows < matrix->numb_columns)
    {
        delete_specific_columns(matrix);
    }
}
