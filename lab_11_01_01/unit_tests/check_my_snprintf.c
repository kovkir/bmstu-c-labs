#include "../inc/check_my_snprintf.h"

START_TEST(o_specifier)
{
    char first_buf[SIZE_BUF + 1];
    char second_buf[SIZE_BUF + 1];

    int number = 66;

    int numb_ch_one = my_snprintf(first_buf, SIZE_BUF, "%o", number);
    int numb_ch_two = snprintf(second_buf, SIZE_BUF, "%o", number);

    assert(numb_ch_one == numb_ch_two);

    int r = compare_arrays(first_buf, second_buf, numb_ch_one);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(hd_specifier)
{
    char first_buf[SIZE_BUF + 1];
    char second_buf[SIZE_BUF + 1];

    short int number = 123;

    int numb_ch_one = my_snprintf(first_buf, SIZE_BUF, "%hd", number);
    int numb_ch_two = snprintf(second_buf, SIZE_BUF, "%hd", number);

    assert(numb_ch_one == numb_ch_two);

    int r = compare_arrays(first_buf, second_buf, numb_ch_one);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(c_specifier)
{
    char first_buf[SIZE_BUF + 1];
    char second_buf[SIZE_BUF + 1];

    char ch = 'k';

    int numb_ch_one = my_snprintf(first_buf, SIZE_BUF, "%c", ch);
    int numb_ch_two = snprintf(second_buf, SIZE_BUF, "%c", ch);

    assert(numb_ch_one == numb_ch_two);

    int r = compare_arrays(first_buf, second_buf, numb_ch_one);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(s_specifier)
{
    char first_buf[SIZE_BUF + 1];
    char second_buf[SIZE_BUF + 1];

    char str[] = "Hello world";

    int numb_ch_one = my_snprintf(first_buf, SIZE_BUF, "%s", str);
    int numb_ch_two = snprintf(second_buf, SIZE_BUF, "%s", str);

    assert(numb_ch_one == numb_ch_two);

    int r = compare_arrays(first_buf, second_buf, numb_ch_one);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

START_TEST(no_specifiers)
{    
    char first_buf[SIZE_BUF + 1];
    char second_buf[SIZE_BUF + 1];

    int numb_ch_one = my_snprintf(first_buf, SIZE_BUF, "Hello world");
    int numb_ch_two = snprintf(second_buf, SIZE_BUF, "Hello world");

    assert(numb_ch_one == numb_ch_two);

    int r = compare_arrays(first_buf, second_buf, numb_ch_one);

    ck_assert_int_eq(r, SUCCESS);
}
END_TEST

Suite *my_snprintf_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, o_specifier);
    tcase_add_test(tcase_pos, hd_specifier);
    tcase_add_test(tcase_pos, c_specifier);
    tcase_add_test(tcase_pos, s_specifier);
    tcase_add_test(tcase_pos, no_specifiers);

    suite_add_tcase(s, tcase_pos);

    return s;
}
