#include "../inc/check_sort.h" 

void sort_check(int *array1, const int len1, int *array2, const int len2)
{
    mysort(array1, len1, sizeof(int), comparator);

    int r = comparison_of_arrays(array1, len1, array2, len2);

    ck_assert_int_eq(r, SUCCESS);
}

START_TEST(norm_sort)
{
    int array1[] = {1, 2, 9, -23, 3, 4, 0, -8, 2};
    int array2[] = {-23, -8, 0, 1, 2, 2, 3, 4, 9};

    sort_check(array1, 9, array2, 9);
}
END_TEST

START_TEST(sort_file_with_one_elem)
{
    int array1[] = {8};
    int array2[] = {8};

    sort_check(array1, 1, array2, 1);
}
END_TEST

START_TEST(file_is_already_sorted)
{
    int array1[] = {-23, -8, 0, 1, 2, 2, 3, 4, 9};
    int array2[] = {-23, -8, 0, 1, 2, 2, 3, 4, 9};

    sort_check(array1, 9, array2, 9);
}
END_TEST

START_TEST(sort_reverse_file)
{
    int array1[] = {9, 8, 8, 7, 2, 1, 0, -1};
    int array2[] = {-1, 0, 1, 2, 7, 8, 8, 9};
 
    sort_check(array1, 8, array2, 8);
}
END_TEST

Suite *sort_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_sort);
    tcase_add_test(tcase_pos, sort_file_with_one_elem);
    tcase_add_test(tcase_pos, file_is_already_sorted);
    tcase_add_test(tcase_pos, sort_reverse_file);

    suite_add_tcase(s, tcase_pos);

    return s;
}