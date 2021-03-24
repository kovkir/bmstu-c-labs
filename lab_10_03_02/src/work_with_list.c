#include "../inc/work_with_list.h"

node_t *add_item_to_list(node_t **head)
{
    node_t **elem_point = head, *new_elem;

    while (*elem_point != NULL)
    {
        elem_point = &(*elem_point)->next;
    }

    new_elem = malloc(sizeof(node_t));

    if (!new_elem)
        return NULL;
    
    new_elem->power = 0;
    new_elem->next = NULL;

    *elem_point = new_elem;

    return new_elem;
}

void free_list(node_t *head)
{
    node_t *p;

    while (head != NULL)
    {
        p = head->next;

        free(head);
        head = p;
    }
}

int prime_number_check(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return NO;
    }

    return YES;
}

int fill_list(node_t **head, int number)
{
    node_t *end_elem;
    int base_degree = 2;

    while (number > 1)
    {   
        end_elem = add_item_to_list(head);
        
        if (!end_elem)
        {
            free_list(*head);
            return MEMORY_ALIGNMENT_ERROR;
        }
        
        while (number % base_degree == 0)
        {
            number /= base_degree;
            end_elem->power++;
        }

        LOG_DEBUG("base_degree = %d", base_degree);

        while(prime_number_check(++base_degree) != YES);
    }

    return SUCCESS;
}

void square_number(node_t *head)
{
    while (head != NULL)
    {
        head->power *= 2;
        head = head->next;
    }
}

int len_list(node_t *head)
{
    int len = 0;

    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

node_t *multiply_two_numbers(node_t *first_head, node_t *second_head)
{
    node_t *long_list_elem, *short_list_elem, *res_head;

    if (len_list(first_head) >= len_list(second_head))
    {
        res_head = first_head;
        long_list_elem = first_head;
        short_list_elem = second_head;
    }
    else
    {
        res_head = second_head;
        long_list_elem = second_head;
        short_list_elem = first_head;
    }

    while (short_list_elem)
    {
        long_list_elem->power += short_list_elem->power;
        short_list_elem = short_list_elem->next;
        long_list_elem = long_list_elem->next;
    }

    return res_head;
}

int get_number_from_list(node_t *head)
{
    int number = 1, base_degree = 2;

    while (head)
    {
        for (int i = 0; i < head->power; i++)
            number *= base_degree;

        while(prime_number_check(++base_degree) != YES);

        head = head->next;
    }
    
    return number;
}

int div_of_two_numbers(node_t *first_head, node_t *second_head, node_t **res_head)
{
    int first_number, second_number;

    first_number = get_number_from_list(first_head);
    second_number = get_number_from_list(second_head);

    free_list(first_head);
    free_list(second_head);

    LOG_DEBUG("%d", first_number);
    LOG_DEBUG("%d", second_number);

    int res_div = first_number / second_number;

    LOG_DEBUG("%d", res_div);

    if (!res_div)
        return EMPTY_LIST;

    int r = fill_list(res_head, res_div);

    return r;
}
