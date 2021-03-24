#include "../inc/check_main.h"   

int compare_arrays(product *array, const int numb_of_prod, 
product *res_array, const int res_numb_of_prod)
{
    return SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = read_suite(s);

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
