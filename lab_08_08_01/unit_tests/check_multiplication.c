#include "../inc/check_multiplication.h" 

START_TEST(norm_matrix_multipl)
{
    matrix_t matrix_a;

    matrix_a.numb_rows = 3;
    matrix_a.numb_columns = matrix_a.numb_rows;

    matrix_a.matrix = allocate_matrix(matrix_a.numb_rows, matrix_a.numb_columns);
    assert(matrix_a.matrix);

    matrix_a.matrix[0][0] = 1;
    matrix_a.matrix[0][1] = 2;
    matrix_a.matrix[0][2] = 3;
    matrix_a.matrix[1][0] = 4;
    matrix_a.matrix[1][1] = 5;
    matrix_a.matrix[1][2] = 6;
    matrix_a.matrix[2][0] = 7;
    matrix_a.matrix[2][1] = 8;
    matrix_a.matrix[2][2] = 9;

    matrix_t matrix_b;

    matrix_b.numb_rows = 3;
    matrix_b.numb_columns = matrix_b.numb_rows;

    matrix_b.matrix = allocate_matrix(matrix_b.numb_rows, matrix_b.numb_columns);
    assert(matrix_b.matrix);

    matrix_b.matrix[0][0] = 0;
    matrix_b.matrix[0][1] = 1;
    matrix_b.matrix[0][2] = 0;
    matrix_b.matrix[1][0] = 2;
    matrix_b.matrix[1][1] = 0;
    matrix_b.matrix[1][2] = 2;
    matrix_b.matrix[2][0] = 0;
    matrix_b.matrix[2][1] = 3;
    matrix_b.matrix[2][2] = 0;

    matrix_t matrix_res;

    matrix_res.numb_rows = 3;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 4;
    matrix_res.matrix[0][1] = 10;
    matrix_res.matrix[0][2] = 4;
    matrix_res.matrix[1][0] = 10;
    matrix_res.matrix[1][1] = 22;
    matrix_res.matrix[1][2] = 10;
    matrix_res.matrix[2][0] = 16;
    matrix_res.matrix[2][1] = 34;
    matrix_res.matrix[2][2] = 16;
    
    matrix_t matrix_c;

    matrix_c.numb_rows = 3;
    matrix_c.numb_columns = matrix_c.numb_rows;

    matrix_c.matrix = allocate_matrix(matrix_c.numb_rows, matrix_c.numb_columns);
    assert(matrix_c.matrix);

    matrix_multiplication(&matrix_c, &matrix_a, &matrix_b);

    int r = comparison_of_matrices(matrix_c, matrix_res);

    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix_a.matrix, matrix_a.numb_rows);
    free_matrix(matrix_b.matrix, matrix_b.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
    free_matrix(matrix_c.matrix, matrix_c.numb_rows);
}
END_TEST

START_TEST(multipl_by_identity_matrix)
{
    matrix_t matrix_a;

    matrix_a.numb_rows = 3;
    matrix_a.numb_columns = matrix_a.numb_rows;

    matrix_a.matrix = allocate_matrix(matrix_a.numb_rows, matrix_a.numb_columns);
    assert(matrix_a.matrix);

    matrix_a.matrix[0][0] = 1;
    matrix_a.matrix[0][1] = 2;
    matrix_a.matrix[0][2] = 3;
    matrix_a.matrix[1][0] = 4;
    matrix_a.matrix[1][1] = 5;
    matrix_a.matrix[1][2] = 6;
    matrix_a.matrix[2][0] = 7;
    matrix_a.matrix[2][1] = 8;
    matrix_a.matrix[2][2] = 9;

    matrix_t matrix_b;

    matrix_b.numb_rows = 3;
    matrix_b.numb_columns = matrix_b.numb_rows;

    matrix_b.matrix = allocate_matrix(matrix_b.numb_rows, matrix_b.numb_columns);
    assert(matrix_b.matrix);

    matrix_b.matrix[0][0] = 1;
    matrix_b.matrix[0][1] = 0;
    matrix_b.matrix[0][2] = 0;
    matrix_b.matrix[1][0] = 0;
    matrix_b.matrix[1][1] = 1;
    matrix_b.matrix[1][2] = 0;
    matrix_b.matrix[2][0] = 0;
    matrix_b.matrix[2][1] = 0;
    matrix_b.matrix[2][2] = 1;

    matrix_t matrix_res;

    matrix_res.numb_rows = 3;
    matrix_res.numb_columns = matrix_res.numb_rows;

    matrix_res.matrix = allocate_matrix(matrix_res.numb_rows, matrix_res.numb_columns);
    assert(matrix_res.matrix);

    matrix_res.matrix[0][0] = 1;
    matrix_res.matrix[0][1] = 2;
    matrix_res.matrix[0][2] = 3;
    matrix_res.matrix[1][0] = 4;
    matrix_res.matrix[1][1] = 5;
    matrix_res.matrix[1][2] = 6;
    matrix_res.matrix[2][0] = 7;
    matrix_res.matrix[2][1] = 8;
    matrix_res.matrix[2][2] = 9;
    
    matrix_t matrix_c;

    matrix_c.numb_rows = 3;
    matrix_c.numb_columns = matrix_c.numb_rows;

    matrix_c.matrix = allocate_matrix(matrix_c.numb_rows, matrix_c.numb_columns);
    assert(matrix_c.matrix);

    matrix_multiplication(&matrix_c, &matrix_a, &matrix_b);

    int r = comparison_of_matrices(matrix_c, matrix_res);
    
    ck_assert_int_eq(r, SUCCESS);

    free_matrix(matrix_a.matrix, matrix_a.numb_rows);
    free_matrix(matrix_b.matrix, matrix_b.numb_rows);
    free_matrix(matrix_res.matrix, matrix_res.numb_rows);
    free_matrix(matrix_c.matrix, matrix_c.numb_rows);
}
END_TEST

Suite *multiplication_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_matrix_multipl);
    tcase_add_test(tcase_pos, multipl_by_identity_matrix);

    suite_add_tcase(s, tcase_pos);
    
    return s;
}
