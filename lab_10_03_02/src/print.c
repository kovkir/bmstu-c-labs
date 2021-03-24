#include "../inc/print.h"

void print_list(node_t *head)
{
    while (head)
    {
        printf("%d ", head->power);
        head = head->next;
    }
    
    printf("L\n");
}