#include "../inc/check_reverse.h"

START_TEST(norm_list_reverse)
{
    salary_t array;

    array.array = malloc(4 * sizeof(int));
    assert(array.array);

    array.size = 4;
    array.array[0] = 5;
    array.array[1] = 2;
    array.array[2] = 6;
    array.array[3] = 0;

    node_t *head = NULL;

    int r = fill_list(&head, &array);
    assert(r == SUCCESS);

    head = reverse(head);

    int *point_array[] = {array.array + 3, array.array + 2, array.array + 1, array.array};

    r = comparing_list_to_array(head, point_array, array.size);

    free_list(head);
    free(array.array);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(one_elem_in_list)
{
    salary_t array;

    array.array = malloc(1 * sizeof(int));
    assert(array.array);

    array.size = 1;
    array.array[0] = 5;

    node_t *head = NULL;

    int r = fill_list(&head, &array);
    assert(r == SUCCESS);

    head = reverse(head);

    int *point_array[] = {array.array};

    r = comparing_list_to_array(head, point_array, array.size);

    free_list(head);
    free(array.array);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

Suite *reverse_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_list_reverse);
    tcase_add_test(tcase_pos, one_elem_in_list);

    suite_add_tcase(s, tcase_pos);
    
    return s;
}
