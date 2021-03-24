#include "../inc/check_delete.h"

START_TEST(delete_rows)
{
    matrix_t matrix;

    matrix.numb_rows = 5;
    matrix.numb_columns = 1;

    matrix.matrix = allocate_matrix(matrix.numb_rows, matrix.numb_columns);
    assert(matrix.matrix);

    matrix.matrix[0][0] = 5;
    matrix.matrix[1][0] = 2;
    matrix.matrix[2][0] = 3;
    matrix.matrix[3][0] = 4;
    matrix.matrix[4][0] = 1;

    matrix_t matrix_res;

    matrix_res.numb_rows = 1;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 5;
 
    remove_desired_elements(&matrix);

    int r = comparison_of_matrices(matrix, matrix_res);

    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix.matrix, matrix.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
}
END_TEST

START_TEST(delete_columns)
{
    matrix_t matrix;

    matrix.numb_rows = 1;
    matrix.numb_columns = 5;

    matrix.matrix = allocate_matrix(matrix.numb_rows, matrix.numb_columns);
    assert(matrix.matrix);

    matrix.matrix[0][0] = 5;
    matrix.matrix[0][1] = 2;
    matrix.matrix[0][2] = 3;
    matrix.matrix[0][3] = 4;
    matrix.matrix[0][4] = 1;

    matrix_t matrix_res;

    matrix_res.numb_rows = 1;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 5;
 
    remove_desired_elements(&matrix);

    int r = comparison_of_matrices(matrix, matrix_res);

    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix.matrix, matrix.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
}
END_TEST

START_TEST(do_not_delete)
{
    matrix_t matrix;

    matrix.numb_rows = 2;
    matrix.numb_columns = 2;

    matrix.matrix = allocate_matrix(matrix.numb_rows, matrix.numb_columns);
    assert(matrix.matrix);

    matrix.matrix[0][0] = 5;
    matrix.matrix[0][1] = 2;
    matrix.matrix[1][0] = 3;
    matrix.matrix[1][1] = 4;

    matrix_t matrix_res;

    matrix_res.numb_rows = 2;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 5;
    matrix_res.matrix[0][1] = 2;
    matrix_res.matrix[1][0] = 3;
    matrix_res.matrix[1][1] = 4;
 
    remove_desired_elements(&matrix);

    int r = comparison_of_matrices(matrix, matrix_res);

    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix.matrix, matrix.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
}
END_TEST

Suite *delete_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, delete_rows);
    tcase_add_test(tcase_pos, delete_columns);
    tcase_add_test(tcase_pos, do_not_delete);

    suite_add_tcase(s, tcase_pos);
    
    return s;
}
