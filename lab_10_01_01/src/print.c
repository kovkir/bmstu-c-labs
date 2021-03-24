#include "../inc/print.h"

void print_list(node_t *head, FILE *f)
{
    node_t *p = head;

    while (p != NULL)
    {
        fprintf(f, "%d\n", *(int*) p->data);
        p = p->next;
    }
}
