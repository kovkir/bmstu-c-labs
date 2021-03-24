#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <string.h>

#include "errors.h"
#include "structures.h"

#define LEN_ACTION 3

int read_action(char action[]);

int read_number(int *number);

#endif
