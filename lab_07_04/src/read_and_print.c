#include "../inc/read_and_print.h"

int number_of_elements_in_file(FILE *const f, int *const numb_elem)
{
    int number;
    
    *numb_elem = 0;
    
    while (fscanf(f, "%d", &number) == 1)
    {
        (*numb_elem)++;
    }
    
    if (!feof(f))
    {
        return ERROR_READING_FROM_FILE;
    }
    
    if (*numb_elem == 0)
    {
        return FILE_EMPTY;
    }
    
    return SUCCESS;
}

int fill_the_array(int *const *const pb_array, int *const *const pe_array, FILE *const f)
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

int create_and_fill_an_array(int **pb_array, int **pe_array, FILE *const f)
{
    int r, numb_elem;
    
    r = number_of_elements_in_file(f, &numb_elem);
    
    if (r)
        return r;

    *pb_array = malloc(numb_elem * sizeof(int));
    
    if (!*pb_array)
        return MEMORY_ALLOCATION_ERROR;
    
    *pe_array = *pb_array + numb_elem;
    
    r = fill_the_array(pb_array, pe_array, f);

    if (r)
        return r;

    return SUCCESS;
}

int read_data(const char *name_in_file, char filt, int **pb_array, int **pe_array)
{
    int r;
    FILE *f;
    
    f = fopen(name_in_file, "r");
    
    if (f == NULL)
    {
        return FILE_OPEN_ERROR;
    }
    
    r = create_and_fill_an_array(pb_array, pe_array, f);
    
    if (r)
    {
        free(*pb_array);
        return r;
    }

    if (fclose(f))
    {
        free(*pb_array);
        return FAILED_TO_CLOSE_FILE;
    }
    
    if (filt == YES)
    {
        int *pbf_array = NULL, *pef_array = NULL;
        
        r = key(*pb_array, *pe_array, &pbf_array, &pef_array);
        
        if (r)
        {
            free(*pb_array);
            free(pbf_array);
            return r;
        }
        else
        {
            free(*pb_array);
            *pb_array = pbf_array;
            *pe_array = pef_array;
        }
    }
    
    LOG_DEBUG("len array after filtration = %ld", *pe_array - *pb_array);
    
    return SUCCESS;
}

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