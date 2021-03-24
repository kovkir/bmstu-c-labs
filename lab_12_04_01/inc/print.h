#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>

#include "errors.h"
#include "macrologger.h"

void print_array(int *const pb_array, int *const pe_array, FILE *const f);

int write_data_to_file(const char *name_out_file, int *pb_array, int *pe_array);

#endif
