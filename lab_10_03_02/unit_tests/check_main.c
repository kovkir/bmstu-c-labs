#include "../inc/check_main.h"

int comparing_list_to_array(node_t *head, int *array, int size)
{   
    int i = 0;

    while (head)
    {
        if (size > 0 && head->power != array[i++])
            return ELEMENTS_ARE_DIFFERENT;

        head = head->next;
        size--;
    }

    if (size)
        return LISTS_ARE_DIFFERENT;

    return SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = mul_suite(s);
    s = sqr_suite(s);
    s = div_suite(s);

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
