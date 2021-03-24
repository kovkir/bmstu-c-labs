#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#include "read_and_print.h"
#include "sort.h"
#include "errors.h"

#define YES 'y'
#define NO 'n'

int parse_args(int argc, const char *argv[], 
const char **name_in_file, const char **name_out_file, char *filt);

#endif 
