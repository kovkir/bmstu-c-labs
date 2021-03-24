#ifndef WORK_WITH_LIST_H
#define WORK_WITH_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "structures.h"
#include "macrologger.h"

#define NO 1
#define YES 0

node_t *add_item_to_list(node_t **head);

void free_list(node_t *head);

int prime_number_check(int number);

int fill_list(node_t **head, int number);

void square_number(node_t *head);

int len_list(node_t *head);

node_t *multiply_two_numbers(node_t *first_head, node_t *second_head);

int div_of_two_numbers(node_t *first_head, node_t *second_head, node_t **res_head);

#endif
