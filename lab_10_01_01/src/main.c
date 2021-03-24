#include "../inc/main.h"

int parse_args(int argc, const char *argv[], 
const char **in_file, const char **out_file)
{
    if (argc != 3)
        return ARGUMENTS_PASSED_INCORRECTLY;

    *in_file = argv[1];
    *out_file = argv[2];

    return SUCCESS;
}

int main(int argc, const char *argv[])
{
    const char *in_file, *out_file;

    int r = parse_args(argc, argv, &in_file, &out_file);
    
    if (r)
        return r;

    FILE *f;
    
    f = fopen(in_file, "r");
    
    if (!f)
        return FILE_DOES_NOT_EXIST;

    salary_t array;

    r = read_array(&array, f);

    if (r)
        return r;

    if (fclose(f))
        return COULD_NOT_CLOSE_FILE;

    node_t *head = NULL;

    r = fill_list(&head, &array);

    if (r)
        return r;

    r = process_list(&head, &array);

    if (r)
    {
        free_list(head);
        free(array.array);
    }

    f = fopen(out_file, "w");
    
    if (!f)
        return FILE_DOES_NOT_EXIST;

    print_list(head, f);

    if (fclose(f))
        return COULD_NOT_CLOSE_FILE;

    free_list(head);
    free(array.array);

    return SUCCESS;
}
