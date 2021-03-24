#include "../inc/check_mul.h"

START_TEST(norm_mul)
{
    int first_numb = 3;

    node_t *first_head = NULL;

    int r = fill_list(&first_head, first_numb);
    assert(!r);

    int second_numb = 25;

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);
    assert(!r);

    node_t *res_head = multiply_two_numbers(first_head, second_head);

    int array[] = {0, 1, 2};

    r = comparing_list_to_array(res_head, array, 3);

    free_list(first_head);
    free_list(second_head);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(unit_mul)
{
    int first_numb = 7;

    node_t *first_head = NULL;

    int r = fill_list(&first_head, first_numb);
    assert(!r);

    int second_numb = 1;

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);
    assert(!r);

    node_t *res_head = multiply_two_numbers(first_head, second_head);

    int array[] = {0, 0, 0, 1};

    r = comparing_list_to_array(res_head, array, 4);

    free_list(first_head);
    free_list(second_head);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

Suite *mul_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_mul);
    tcase_add_test(tcase_pos, unit_mul);

    suite_add_tcase(s, tcase_pos);
    
    return s;
}
