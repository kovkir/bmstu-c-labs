#include "../inc/check_key.h"

// //Positives

START_TEST(filter_normal)
{
    int pb_src[] = {1, 2, 9, -23, 3, 4, 0, -8, 2};
    int *pe_src = pb_src + 9;

    int res_array[] = {1, 2, 9, 3, 4, 0, 2};
    int len_res_array = 7;

    int *pb_dst, *pe_dst;

    int r = create_array(&pb_dst, &pe_dst, 9);
    assert(r == SUCCESS);

    void* hlib;
    fn_key_t key;

    hlib = dlopen("./key_lib/libkey.so", RTLD_NOW);
    assert(hlib);

    key = (fn_key_t) dlsym(hlib, "key");
    assert(key);

    r = key(pb_src, pe_src, &pb_dst, &pe_dst);
    assert(r == SUCCESS);

    dlclose(hlib);

    int len = pe_dst - pb_dst;
    r = comparison_of_arrays(pb_dst, len, res_array, len_res_array);

    ck_assert_int_eq(r, SUCCESS);

    free(pb_dst);
}
END_TEST

//Negatives

START_TEST(invalid_pointer_beg_array)
{
    int array[] = {1, 2, 9, -23, 3, 4, 0, -8, 2};
    int *pb_src = NULL;
    int *pe_src = array + 9;

    int *pb_dst, *pe_dst;

    int r = create_array(&pb_dst, &pe_dst, 9);
    assert(r == SUCCESS);

    void* hlib;
    fn_key_t key;

    hlib = dlopen("./key_lib/libkey.so", RTLD_NOW);
    assert(hlib);

    key = (fn_key_t) dlsym(hlib, "key");
    assert(key);

    r = key(pb_src, pe_src, &pb_dst, &pe_dst);

    dlclose(hlib);

    ck_assert_int_eq(r, INCORRECT_DATA_FOR_FILTRATION);

    free(pb_dst);
}
END_TEST

START_TEST(invalid_pointer_end_array)
{
    int pb_src[] = {1, 2, 9, -23, 3, 4, 0, -8, 2};
    int *pe_src = NULL;

    int *pb_dst, *pe_dst;

    int r = create_array(&pb_dst, &pe_dst, 9);
    assert(r == SUCCESS);

    void* hlib;
    fn_key_t key;

    hlib = dlopen("./key_lib/libkey.so", RTLD_NOW);
    assert(hlib);

    key = (fn_key_t) dlsym(hlib, "key");
    assert(key);

    r = key(pb_src, pe_src, &pb_dst, &pe_dst);

    dlclose(hlib);

    ck_assert_int_eq(r, INCORRECT_DATA_FOR_FILTRATION);

    free(pb_dst);
}
END_TEST

START_TEST(pe_array_not_less_pb_array)
{
    int pb_src[] = {1, 2, 9, -23, 3, 4, 0, -8, 2};
    int *pe_src = pb_src - 1;

    int *pb_dst, *pe_dst;

    int r = create_array(&pb_dst, &pe_dst, 9);
    assert(r == SUCCESS);

    void* hlib;
    fn_key_t key;

    hlib = dlopen("./key_lib/libkey.so", RTLD_NOW);
    assert(hlib);

    key = (fn_key_t) dlsym(hlib, "key");
    assert(key);

    r = key(pb_src, pe_src, &pb_dst, &pe_dst);

    dlclose(hlib);

    ck_assert_int_eq(r, INCORRECT_DATA_FOR_FILTRATION);

    free(pb_dst);
}
END_TEST

START_TEST(empty_file_after_filtering)
{
    int pb_src[] = {5, 5, 5, 5, 5};
    int *pe_src = pb_src + 5;

    int *pb_dst, *pe_dst;

    int r = create_array(&pb_dst, &pe_dst, 5);
    assert(r == SUCCESS);

    void* hlib;
    fn_key_t key;

    hlib = dlopen("./key_lib/libkey.so", RTLD_NOW);
    assert(hlib);

    key = (fn_key_t) dlsym(hlib, "key");
    assert(key);

    r = key(pb_src, pe_src, &pb_dst, &pe_dst);

    dlclose(hlib);

    ck_assert_int_eq(r, NEW_FILE_EMPTY);

    free(pb_dst);
}
END_TEST

Suite *key_suite(Suite *s)
{
    TCase *tcase_pos, *tcase_neg;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, filter_normal);

    suite_add_tcase(s, tcase_pos);

    tcase_neg = tcase_create("negatives");

    tcase_add_test(tcase_neg, invalid_pointer_beg_array);
    tcase_add_test(tcase_neg, invalid_pointer_end_array);
    tcase_add_test(tcase_neg, pe_array_not_less_pb_array);
    tcase_add_test(tcase_neg, empty_file_after_filtering);

    suite_add_tcase(s, tcase_neg);

    return s;
}
