#ifndef READ_H
#define READ_H

#include <stdio.h>

#include "errors.h"
#include "macrologger.h"

int number_of_elements_in_file(FILE *const f, int *const numb_elem);

int fill_array(int *const *const pb_array, int *const *const pe_array, FILE *const f);

#endif
