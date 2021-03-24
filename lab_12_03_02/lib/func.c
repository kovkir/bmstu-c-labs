#define YES 1
#define NO 0

int is_number_prime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return NO;
    }

    return YES;
}

int search_for_prime_number(int number)
{
    while (is_number_prime(++number) == NO);

    return number;
}

void fill_array(int *array, int size)
{
    int prime_numb = 2;

    for (int i = 0; i < size; i++)
    {
        array[i] = prime_numb;
        prime_numb = search_for_prime_number(prime_numb);
    }
}

int add_elem_after_even(int *arr, int size_arr, int *res_arr, int size_res_arr, int number)
{
    int index = 0;
    
    for (int i = 0; i < size_arr; i++)
    {
        if (index < size_res_arr)
            res_arr[index] = arr[i];
        
        index++;

        if (arr[i] % 2 == 0)
        {
            if (index < size_res_arr)
                res_arr[index] = number;

            index++;
        }
    }

    return index;
}
