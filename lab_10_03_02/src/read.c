#include "../inc/read.h"

int read_action(char action[])
{
    int r = scanf("%4s", action);

    if (r != 1)
        return FAILED_TO_READ_ACTION;

    if (action[3] != '\0'
        || !(!strncmp(action, "out", LEN_ACTION)
        || !strncmp(action, "mul", LEN_ACTION)
        || !strncmp(action, "sqr", LEN_ACTION)
        || !strncmp(action, "div", LEN_ACTION)))
    {
        return WRONG_ACTION;
    }

    return SUCCESS;
}

int read_number(int *number)
{
    int r = scanf("%d", number);

    if (r != 1)
        return FAILED_TO_READ_NUMBER;

    if (*number <= 0)
        return NEGATIVE_NUMBER;

    return SUCCESS;
}
