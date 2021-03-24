#include "../inc/work.h"

int create_array(int **pb_array, int **pe_array, int numb_elem)
{
    *pb_array = malloc(numb_elem * sizeof(int));
    
    if (!*pb_array)
        return MEMORY_ALLOCATION_ERROR;
    
    *pe_array = *pb_array + numb_elem;
    
    return SUCCESS;
}

int read_data(const char *name_in_file, char filt, int **pb_array, int **pe_array)
{
    int r, numb_elem;
    FILE *f;
    
    f = fopen(name_in_file, "r");
    
    if (f == NULL)
        return FILE_OPEN_ERROR;
    
    r = number_of_elements_in_file(f, &numb_elem);
    
    if (r)
        return r;

    r = create_array(pb_array, pe_array, numb_elem);
    
    if (r)
        return r;
    
    r = fill_array(pb_array, pe_array, f);

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
        
        r = create_array(&pbf_array, &pef_array, numb_elem);
    
        if (r)
        {
            free(*pb_array);
            return r;
        }

        void* hlib;
        fn_key_t key;

        hlib = dlopen("./key_lib/libkey.so", RTLD_NOW);

        if (!hlib)
        {
            free(*pb_array);
            return CAN_NOT_OPEN_LIBRARY;
        }

        key = (fn_key_t) dlsym(hlib, "key");

        if (!key)
        {
            free(*pb_array);
            return CAN_NOT_LOAD_FUNCTION;
        }

        r = key(*pb_array, *pe_array, &pbf_array, &pef_array);
        
        dlclose(hlib);
        
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
