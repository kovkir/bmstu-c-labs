#include "../inc/check_main.h"

int compare_arrays(char *first_array, char *second_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (first_array[i] != second_array[i])
        {
            return DIFFERENT_ARRAYS; 
        }
    }

    return SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = my_snprintf_suite(s);

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
