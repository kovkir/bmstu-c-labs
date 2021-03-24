#include "../inc/sort.h"

node_t *sort(node_t *head, int (*comparator)(const void*, const void*))
{
    node_t *new_head = NULL, *elem = head, *next_elem;

    // print_list(head, stdout);

    while (elem)
    {
        next_elem = elem->next;
        sorted_insert(&new_head, elem, comparator);
        elem = next_elem;
    }

    // print_list(new_head, stdout);

    return new_head;
}

void sorted_insert(node_t **head, node_t *element,
int (*comparator)(const void*, const void*))
{
    node_t *elem_list = *head, *prev_elem = NULL;

    while (elem_list)
    {
        if (comparator(element->data, elem_list->data) < 0)
        {
            insert_new_elem(prev_elem, elem_list, element, head);
            return;
        }

        prev_elem = elem_list;
        elem_list = elem_list->next;
    }

    insert_new_elem(prev_elem, NULL, element, head);
}

void insert_new_elem(node_t *prev_elem, node_t *next_elem, node_t *element, node_t **head)
{   
    if (!prev_elem)
    {
        element->next = next_elem;
        *head = element;
    }
    else
    {
        prev_elem->next = element;
        element->next = next_elem;
    }

    LOG_DEBUG("%d", *(int*) element->data);
}
