#include "../inc/check_sqr.h"

START_TEST(norm_sqr)
{
    int number = 21;
    node_t *head = NULL;

    int r = fill_list(&head, number);
    assert(!r);
    
    int array[] = {0, 2, 0, 2};

    square_number(head);

    r = comparing_list_to_array(head, array, 4);

    free_list(head);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(unit_sqr)
{
    int number = 1;
    node_t *head = NULL;

    int r = fill_list(&head, number);
    assert(!r);
    
    int *array = NULL;

    square_number(head);

    r = comparing_list_to_array(head, array, 0);

    free_list(head);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

Suite *sqr_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_sqr);
    tcase_add_test(tcase_pos, unit_sqr);

    suite_add_tcase(s, tcase_pos);
    
    return s;
}
