#include "../inc/prog_actions.h"

int display_number_as_list(void)
{   
    int number, r;
 
    r = read_number(&number);

    if (r)
        return r;

    node_t *head = NULL;

    r = fill_list(&head, number);

    if (r)
        return r;

    print_list(head);
    free_list(head);

    return SUCCESS;
}

int multipl_of_two_numbers(void)
{
    int first_numb, r;

    r = read_number(&first_numb);

    if (r)
        return r;

    node_t *first_head = NULL;

    r = fill_list(&first_head, first_numb);

    if (r)
        return r;

    int second_numb;

    r = read_number(&second_numb);

    if (r)
    {
        free_list(first_head);
        return r;
    }

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);

    if (r)
    {
        free_list(first_head);
        return r;
    }

    node_t *res_head = multiply_two_numbers(first_head, second_head);

    print_list(res_head);

    free_list(first_head);
    free_list(second_head);

    return SUCCESS;
}

int squaring_number(void)
{
    int number, r;

    r = read_number(&number);

    if (r)
        return r;

    node_t *head = NULL;

    r = fill_list(&head, number);

    if (r)
        return r;
    
    square_number(head);

    print_list(head);
    free_list(head);

    return SUCCESS;
}

int div_number_without_remainder(void)
{
    int first_numb, r;

    r = read_number(&first_numb);

    if (r)
        return r;

    node_t *first_head = NULL;

    r = fill_list(&first_head, first_numb);

    if (r)
        return r;

    int second_numb;

    r = read_number(&second_numb);

    if (r)
    {
        free_list(first_head);
        return r;
    }

    node_t *second_head = NULL;

    r = fill_list(&second_head, second_numb);

    if (r)
    {
        free_list(first_head);
        return r;
    }

    node_t *res_head = NULL;

    r = div_of_two_numbers(first_head, second_head, &res_head);

    if (r)
        return r;

    print_list(res_head);
    free_list(res_head);

    return SUCCESS;
}
