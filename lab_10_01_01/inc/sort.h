#ifndef SORT_H
#define SORT_H

#include <stdio.h>

#include "structures.h"
#include "work_with_list.h"
#include "print.h"
#include "macrologger.h"

node_t *sort(node_t *head, int (*comparator)(const void*, const void*));

void sorted_insert(node_t **head, node_t *element,
int (*comparator)(const void*, const void*));

void insert_new_elem(node_t *prev_elem, node_t *next_elem, node_t *element, node_t **head);

#endif
