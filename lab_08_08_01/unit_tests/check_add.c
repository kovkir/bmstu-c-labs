#include "../inc/check_add.h"

START_TEST(matrix_changed)
{
    matrix_t matrix;

    matrix.numb_rows = 2;
    matrix.numb_columns = matrix.numb_rows;

    matrix.matrix = allocate_matrix(matrix.numb_rows, matrix.numb_columns);
    assert(matrix.matrix);

    matrix.matrix[0][0] = 1;
    matrix.matrix[0][1] = 2;
    matrix.matrix[1][0] = 3;
    matrix.matrix[1][1] = 4;

    matrix_t matrix_res;

    matrix_res.numb_rows = 4;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 1;
    matrix_res.matrix[0][1] = 2;
    matrix_res.matrix[0][2] = 1;
    matrix_res.matrix[0][3] = 1;
    matrix_res.matrix[1][0] = 3;
    matrix_res.matrix[1][1] = 4;
    matrix_res.matrix[1][2] = 3;
    matrix_res.matrix[1][3] = 3;
    matrix_res.matrix[2][0] = 1;
    matrix_res.matrix[2][1] = 2;
    matrix_res.matrix[2][2] = 1;
    matrix_res.matrix[2][3] = 1;
    matrix_res.matrix[3][0] = 1;
    matrix_res.matrix[3][1] = 2;
    matrix_res.matrix[3][2] = 1;
    matrix_res.matrix[3][3] = 1;
    
    int r = change_matrix(&matrix, matrix_res.numb_rows);  
    assert(!r);

    r = comparison_of_matrices(matrix, matrix_res);

    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix.matrix, matrix.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
}
END_TEST

START_TEST(matrix_has_not_changed)
{
    matrix_t matrix;

    matrix.numb_rows = 2;
    matrix.numb_columns = matrix.numb_rows;

    matrix.matrix = allocate_matrix(matrix.numb_rows, matrix.numb_columns);
    assert(matrix.matrix);

    matrix.matrix[0][0] = 1;
    matrix.matrix[0][1] = 2;
    matrix.matrix[1][0] = 3;
    matrix.matrix[1][1] = 4;

    matrix_t matrix_res;
    
    matrix_res.numb_rows = 2;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 1;
    matrix_res.matrix[0][1] = 2;
    matrix_res.matrix[1][0] = 3;
    matrix_res.matrix[1][1] = 4;

    int r = change_matrix(&matrix, matrix_res.numb_rows); 
    assert(!r);

    r = comparison_of_matrices(matrix, matrix_res);

    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix.matrix, matrix.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
}
END_TEST

Suite *add_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, matrix_changed);
    tcase_add_test(tcase_pos, matrix_has_not_changed);

    suite_add_tcase(s, tcase_pos);

    return s;
}
