#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void swap(char *one_elem, char *two_elem, size_t size);

int comparator(const void *val1, const void *val2);

void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif
