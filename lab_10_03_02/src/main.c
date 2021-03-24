#include "../inc/main.h"

int main(void)
{   
    char action[LEN_ACTION + 2];

    int r = read_action(action);
    
    if (r)
        return r;

    if (action[0] == 'o')
    {
        r = display_number_as_list();
    }
    else if (action[0] == 'm')
    {
        r = multipl_of_two_numbers();
    }
    else if (action[0] == 's')
    {
        r = squaring_number();
    }
    else if (action[0] == 'd')
    {
        r = div_number_without_remainder();
    }

    return r;
}
