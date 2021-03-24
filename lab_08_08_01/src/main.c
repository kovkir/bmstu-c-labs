#include "../inc/main.h"

int main(void)
{   
    int r;
    matrix_t matrix_a, matrix_b;

    r = read_matrices(&matrix_a, &matrix_b);

    if (r)
        return r;

    remove_desired_elements(&matrix_a);
    remove_desired_elements(&matrix_b);

    r = add_row_columns_to_matrices(&matrix_a, &matrix_b);

    if (r)
        return r;

    r = raise_matrices_to_power(&matrix_a, &matrix_b);

    if (r)
        return r;

    matrix_t matrix_res;

    r = calculate_result_matrix(&matrix_res, &matrix_a, &matrix_b);

    if (r)
        return r;

    print_matrix(&matrix_res);

    free_matrix(matrix_a.matrix, matrix_a.numb_rows);
    free_matrix(matrix_b.matrix, matrix_b.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);

    return SUCCESS;
}
