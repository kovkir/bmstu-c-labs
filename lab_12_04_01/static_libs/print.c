#include "../inc/print.h"

void print_array(int *const pb_array, int *const pe_array, FILE *const f)
{
    const int *begin = pb_array, *end = pe_array;
    
    while (begin < end)
    {
        fprintf(f, "%d ", *(begin++));
        LOG_DEBUG("array element = %d", *(begin - 1));
    }
}

int write_data_to_file(const char *name_out_file, int *pb_array, int *pe_array)
{
    FILE *f = fopen(name_out_file, "w");
    
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }

    print_array(pb_array, pe_array, f);
    
    if (fclose(f))
    {
        return FAILED_TO_CLOSE_FILE;
    }
    
    return SUCCESS;
}
