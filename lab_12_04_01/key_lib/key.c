#include "../inc/key.h"

double find_arithmetic_mean(const int *const begin, const int *const end)
{
    const int *pb = begin;
    int sum_elem = 0, numb_all_elem = 0;
    double average;
    
    while (pb < end)
    {
        sum_elem += *(pb++);
        numb_all_elem++;
    }
    
    average = (double) sum_elem / numb_all_elem;
    
    return average;
}

int find_number_required_elements(const int *const begin, const int *const end,
const double average)
{
    const int *pb = begin;
    int numb_req_elem = 0;
    
    while (pb < end)
    {
        if (*(pb++) > average)
        {
            numb_req_elem++;
        }
    }
    
    return numb_req_elem;
}

void fill_a_new_array(const int *begin, const int *end,
int **begin_fa, int **end_fa, const double average)
{
    const int *pb = begin;
    int *pb_fa = *begin_fa;
    
    while (pb < end)
    {
        if (*pb > average)
        {
            *(pb_fa++) = *pb;
        }

        pb++;
    }

    *end_fa = pb_fa;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
    {
        return INCORRECT_DATA_FOR_FILTRATION;
    }
    
    double average;
    int numb_req_elem;

    average = find_arithmetic_mean(pb_src, pe_src);
    
    LOG_DEBUG("average = %lf", average);

    numb_req_elem = find_number_required_elements(pb_src, pe_src, average);

    LOG_DEBUG("numb_req_elem = %d", numb_req_elem);

    if (numb_req_elem == 0)
    {
        return NEW_FILE_EMPTY;
    }

    fill_a_new_array(pb_src, pe_src, pb_dst, pe_dst, average);

    return SUCCESS;
}
