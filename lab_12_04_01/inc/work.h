#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "errors.h"
#include "key.h"
#include "main.h"
#include "read.h"
#include "macrologger.h"

typedef int (*fn_key_t)(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

int create_array(int **pb_array, int **pe_array, int numb_elem);

int read_data(const char *name_in_file, char filt, int **pb_array, int **pe_array);

#endif
