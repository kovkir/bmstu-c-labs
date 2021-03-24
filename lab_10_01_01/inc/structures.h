#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

typedef struct salary
{
    int *array;
    int size;
} salary_t;

#endif
