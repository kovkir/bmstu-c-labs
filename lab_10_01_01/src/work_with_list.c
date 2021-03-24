#include "../inc/work_with_list.h"

int comparator(const void *var1, const void *var2)
{
    return *((int*) var1) - *((int*) var2);
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    node_t *elem = head;

    while (elem != NULL)
    {
        if (!comparator(data, elem->data))
            return elem;

        elem = elem->next;
    }

    return NULL;
}

void *pop_front(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    node_t *new_head = (*head)->next;
    void *old_date = (*head)->data;

    free(*head);
    *head = new_head;

    return old_date;
}

node_t *reverse(node_t *head)
{
    node_t *new_head = NULL, *new_elem;

    while (head)
    {
        new_elem = malloc(sizeof(node_t));

        if (!new_elem)
        {
            free_list(head);
            free_list(new_head);
            return NULL;
        }

        new_elem->data = pop_front(&head);
        new_elem->next = new_head;

        new_head = new_elem;
    }

    return new_head;
}

void free_list(node_t *head)
{
    node_t *next_elem;

    while (head != NULL)
    {
        next_elem = head->next;

        free(head);
        head = next_elem;
    }
}

int process_list(node_t **head, salary_t *array)
{   
    if (*head == NULL)
        return LIST_IS_EMPTY;

    *head = sort(*head, comparator);

    node_t *elem = find(*head, array->array, comparator);

    if (elem != *head)
        pop_front(head);

    *head = reverse(*head);

    if (*head == NULL)
        return MEMORY_ALIGNMENT_ERROR;
    
    elem = find(*head, array->array, comparator);

    if (elem != *head)
        pop_front(head);

    return SUCCESS;
}
