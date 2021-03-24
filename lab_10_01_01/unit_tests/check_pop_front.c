#include "../inc/check_pop_front.h"

START_TEST(norm_pop_front)
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

    void *old_date = head->data, *date;

    date = pop_front(&head);
    assert(date == old_date);

    int *point_array[] = {array.array + 1, array.array + 2, array.array + 3};

    r = comparing_list_to_array(head, point_array, array.size - 1);

    free_list(head);
    free(array.array);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

Suite *pop_front_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_pop_front);

    suite_add_tcase(s, tcase_pos);
    
    return s;
}
