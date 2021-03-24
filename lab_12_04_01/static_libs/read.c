#include "../inc/read.h"

int number_of_elements_in_file(FILE *const f, int *const numb_elem)
{
    int number;
    
    *numb_elem = 0;
    
    while (fscanf(f, "%d", &number) == 1)
    {
        (*numb_elem)++;
    }
    
    if (!feof(f))
        return ERROR_READING_FROM_FILE;
    
    if (*numb_elem == 0)
        return FILE_EMPTY;
    
    return SUCCESS;
}

int fill_array(int *const *const pb_array, int *const *const pe_array, FILE *const f)
{
    if (fseek(f, 0, SEEK_SET))
    {
        return FILE_POINTER_SHIFT_ERROR;
    }
    
    int r, *begin = *pb_array, *end = *pe_array;
    
    while (begin < end)
    {
        r = fscanf(f, "%d", begin++);

        if (r != 1)
        {
            return ARRAY_FILL_ERROR;
        }

        LOG_DEBUG("array element = %d", *(begin - 1));
    }
    
    return SUCCESS;
}