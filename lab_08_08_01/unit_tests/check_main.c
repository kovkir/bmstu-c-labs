#include "../inc/check_main.h"  

int comparison_of_matrices(const matrix_t matrix_a, const matrix_t matrix_b)
{
    if (matrix_a.numb_rows != matrix_b.numb_rows)
    {
        return DIFFERENT_NUMBER_ROWS;    
    }
    else if (matrix_a.numb_columns != matrix_b.numb_columns)
    {
        return DIFFERENT_NUMBER_COLUMNS; 
    }

    for (int i = 0; i < matrix_a.numb_rows; i++)
    {
        for (int j = 0; j < matrix_a.numb_columns; j++)
        {
            if (matrix_a.matrix[i][j] != matrix_b.matrix[i][j]) 
            { 
                return COMPARE_ERROR; 
            }  
        }
    }

    return SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = add_suite(s);
    s = delete_suite(s);
    s = multiplication_suite(s);

    return s;
}

int main(void)
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int mistakes = srunner_ntests_failed(runner);

    srunner_free(runner);

    return mistakes;
}
