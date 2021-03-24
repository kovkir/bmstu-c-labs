#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "structures.h"
#include "read.h"
#include "print.h"
#include "work_with_list.h"
#include "sort.h"

int parse_args(int argc, const char *argv[], 
const char **in_file, const char **out_file);

#endif
