#include "../inc/check_read.h"

START_TEST(norm_read)
{
    FILE *f;
    
    f = fopen("./func_tests/pos_01_in.txt", "r");
    
    assert(f);
    
    int number_of_products;

    int r = read_number_of_products(f, &number_of_products);
    
    assert(r == SUCCESS);

    product *array = calloc(number_of_products * sizeof(product), sizeof(product));

    assert(array);
    
    r = read_information_into_an_array(f, array, number_of_products);
    
    assert(r == SUCCESS);
    
    r = fclose(f);
    
    assert(!r);
    
    product res_array[3];

    res_array[0].product_name = "Мороженое 3л";
    res_array[1].product_name = "Молоко";
    res_array[2].product_name = "Масло";

    res_array[0].product_price = 53;
    res_array[1].product_price = 34;
    res_array[2].product_price = 29;

    r = compare_arrays(array, number_of_products, res_array, 3);

    ck_assert_int_eq(r, SUCCESS);

    free_array(array, number_of_products);
}
END_TEST

START_TEST(incor_numb_of_prod)
{
    FILE *f;
    
    f = fopen("./func_tests/neg_04_in.txt", "r");
    
    assert(f);
    
    int number_of_products;

    int r = read_number_of_products(f, &number_of_products);
    
    ck_assert_int_eq(r, NUMBER_OF_PRODUCTS_UNKNOWN);
    
    r = fclose(f);
    
    assert(!r);
}
END_TEST

START_TEST(incor_price_entry)
{
    FILE *f;
    
    f = fopen("./func_tests/neg_07_in.txt", "r");
    
    assert(f);
    
    int number_of_products;

    int r = read_number_of_products(f, &number_of_products);
    
    assert(r == SUCCESS);

    product *array = calloc(number_of_products * sizeof(product), sizeof(product));

    assert(array);
    
    r = read_information_into_an_array(f, array, number_of_products);
    
    ck_assert_int_eq(r, FAILED_TO_READ_PRODUCT_PRICE);
    
    r = fclose(f);
    
    assert(!r);
}
END_TEST

START_TEST(incor_name_prod_entry)
{
    FILE *f;
    
    f = fopen("./func_tests/neg_06_in.txt", "r");
    
    assert(f);
    
    int number_of_products;

    int r = read_number_of_products(f, &number_of_products);
    
    assert(r == SUCCESS);

    product *array = calloc(number_of_products * sizeof(product), sizeof(product));

    assert(array);
    
    r = read_information_into_an_array(f, array, number_of_products);
    
    ck_assert_int_eq(r, EMPTY_LINE);
    
    r = fclose(f);
    
    assert(!r);
}
END_TEST

Suite *read_suite(Suite *s)
{
    TCase *tcase_pos;

    tcase_pos = tcase_create("positives");

    tcase_add_test(tcase_pos, norm_read);

    suite_add_tcase(s, tcase_pos);
    
    TCase *tcase_neg;

    tcase_neg = tcase_create("negative");

    tcase_add_test(tcase_neg, incor_numb_of_prod);
    tcase_add_test(tcase_neg, incor_price_entry);
    tcase_add_test(tcase_neg, incor_name_prod_entry);

    suite_add_tcase(s, tcase_neg);

    return s;
}
