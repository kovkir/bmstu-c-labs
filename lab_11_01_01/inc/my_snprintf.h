#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdarg.h>

#include "add_to_buffer.h"

#define SIZE_BUF 100

int my_snprintf(char *buffer, int buf_size, const char *format, ...);

#endif
