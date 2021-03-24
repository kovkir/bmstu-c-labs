#include "../inc/read.h"

int read_array(salary_t *array, FILE *f)
{   
    int *p, r;

    array->array = NULL;
    array->size = 0;

    while (!feof(f))
    {
        p = realloc(array->array, (array->size + 1) * sizeof(int));

        if (!p)
        {
            free(array->array);
            return MEMORY_ALIGNMENT_ERROR;
        }

        array->array = p;
        r = fscanf(f, "%d", array->array + array->size++);

        if (r != 1)
        {
            free(array->array);
            return FAILED_TO_READ_ARRAY_ELEM;
        }
    }

    return SUCCESS;
}

int fill_list(node_t **head, salary_t *array)
{
    node_t *new_elem, **elem_list = head;

    for (int i = 0; i < array->size; i++)
    {
        new_elem = malloc(sizeof(node_t));

        if (!new_elem)
        {
            free_list(*head);
            free(array->array);
            return MEMORY_ALIGNMENT_ERROR;
        }

        new_elem->data = array->array + i;
        new_elem->next = NULL;

        *elem_list = new_elem;
        elem_list = &(*elem_list)->next;
    }

    return SUCCESS;
}
