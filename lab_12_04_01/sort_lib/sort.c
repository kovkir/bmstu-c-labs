#include "../inc/sort.h"

void swap(char *one_elem, char *two_elem, size_t size)
{
    char symbol;
    
    while (size-- > 0)
    {
        symbol = *one_elem;
        *(one_elem++) = *two_elem;
        *(two_elem++) = symbol;
    }
}

int comparator(const void *val1, const void *val2)
{
    return *((int*) val1) - *((int*) val2);
}
 
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    char *begin = first;
    char *end = begin + (number - 1) * size;
    
    for (; begin < end; end -= size)
    {
        for (char *pb = begin, *a, *b; pb < end; pb += size)
        {
            a = pb;
            pb += size;
            b = pb;
            
            if (comparator(a, b) > 0)
            {
                swap(a, b, size);
            }
            
            pb -= size;
        }
    }
}
