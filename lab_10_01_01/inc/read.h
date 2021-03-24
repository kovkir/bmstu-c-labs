#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "structures.h"
#include "work_with_list.h"

int read_array(salary_t *array, FILE *f);

int fill_list(node_t **head, salary_t *array);

#endif
