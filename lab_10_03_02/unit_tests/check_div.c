#include "../inc/check_div.h"

START_TEST(norm_div)
{
    int first_numb = 9;

    node_t *first_head = NULL;

    int r = fill_list(&first_head, first_numb);
    assert(!r);

    int second_numb = 4;

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);
    assert(!r);

    node_t *res_head = NULL;

    r = div_of_two_numbers(first_head, second_head, &res_head);
    assert(!r);

    int array[] = {1};

    r = comparing_list_to_array(res_head, array, 1);

    free_list(res_head);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(unit_div)
{
    int first_numb = 9;

    node_t *first_head = NULL;

    int r = fill_list(&first_head, first_numb);
    assert(!r);

    int second_numb = 9;

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);
    assert(!r);

    node_t *res_head = NULL;

    r = div_of_two_numbers(first_head, second_head, &res_head);
    assert(!r);

    int *array = NULL;

    r = comparing_list_to_array(res_head, array, 0);

    free_list(res_head);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(zero_result)
{
    int first_numb = 4;

    node_t *first_head = NULL;

    int r = fill_list(&first_head, first_numb);
    assert(!r);

    int second_numb = 9;

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);
    assert(!r);

    node_t *res_head = NULL;

    r = div_of_two_numbers(first_head, second_head, &res_head);

    free_list(res_head);

    ck_assert_int_eq(r, EMPTY_LIST);
}
END_TEST

Suite *div_suite(Suite *s)
{
    TCase *tcase_pos, *tcase_neg;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_div);
    tcase_add_test(tcase_pos, unit_div);

    suite_add_tcase(s, tcase_pos);
    
    tcase_neg = tcase_create("negative");

    tcase_add_test(tcase_pos, zero_result);

    suite_add_tcase(s, tcase_neg);
    
    return s;
}
