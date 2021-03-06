#include "../inc/check_main.h"

int comparison_of_arrays(int *array_one, int len_one, int *array_two, int len_two)
{
    if (len_one != len_two)
    {
        return DIFFERENT_LENGTH_OF_ARRAYS;    
    }

    for (int i = 0; i < len_one; i++)
    {
        if (array_one[i] != array_two[i])
        { 
            return ERROR_FOUND;
        }
    }

    return SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = sort_suite(s);
    s = key_suite(s);

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
