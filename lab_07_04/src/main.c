#include "../inc/main.h"

int parse_args(int argc, const char *argv[], 
const char **name_in_file, const char **name_out_file, char *filt)
{
    if ((argc == 4 && *argv[3] == 'f') || argc == 3)
    {
        *name_in_file = argv[1];
        *name_out_file = argv[2];
    }
    else
    {
        return ARGUMENTS_INCORRECTLY_TRANSFERRED;
    }

    *filt = (argc == 3) ? NO : YES;

    return SUCCESS;
}

int main(int argc, const char *argv[])
{
    const char *name_in_file, *name_out_file;
    char filt;

    int r = parse_args(argc, argv, &name_in_file, &name_out_file, &filt);

    if (r)
        return r;

    int *pb_array = NULL, *pe_array = NULL;

    r = read_data(name_in_file, filt, &pb_array, &pe_array);

    if (r)
        return r;

    mysort(pb_array, pe_array - pb_array, sizeof(int), comparator);

    r = write_data_to_file(name_out_file, pb_array, pe_array);
    
    free(pb_array);
    
    return r;
}
