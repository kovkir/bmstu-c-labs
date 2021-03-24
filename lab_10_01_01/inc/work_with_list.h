#ifndef WORK_WITH_LIST
#define WORK_WITH_LIST

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "errors.h"
#include "sort.h"

int comparator(const void *var1, const void *var2);

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));

void *pop_front(node_t **head);

node_t *reverse(node_t *head);

void free_list(node_t *head);

int process_list(node_t **head, salary_t *array);

#endif
