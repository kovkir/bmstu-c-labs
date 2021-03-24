#ifndef READ_AND_PRINT_H
#define READ_AND_PRINT_H

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "key.h"
#include "errors.h"
#include "main.h"

int number_of_elements_in_file(FILE *const f, int *const numb_elem);

int fill_the_array(int *const *const pb_array, int *const *const pe_array, FILE *const f);

int create_and_fill_an_array(int **pb_array, int **pe_array, FILE *const f);

int read_data(const char *name_in_file, char filt, int **pb_array, int **pe_array);

void print_array(int *const pb_array, int *const pe_array, FILE *const f);

int write_data_to_file(const char *name_out_file, int *pb_array, int *pe_array);

#endif
