#ifndef ADD_TO_BUFFER_H
#define ADD_TO_BUFFER_H

#include <stdarg.h>
#include <stdio.h>
#include <math.h>

#include "macrologger.h"

#define MAX_DIGITS_IN_NUMBER 11

void add_char_to_buffer(char **buf_p, char *buf_end, char ch);

int add_number_to_buffer(va_list argptr, char **buf_p, char *buf_end);

int add_string_to_buffer(va_list argptr, char **buf_p, char *buf_end);

int add_octal_number_to_buffer(va_list argptr, char **buf_p, char *buf_end);

#endif
