#include <stdio.h>

int woodcutter(int **tree, const int size)
{
    int res = 0, interim_res = 0, quantity, max_quant = 0, numb_of_diag = 0;

    for (int i = 0; i < size; i++)
    {
        if (tree[i][i] == 1)
            numb_of_diag++;
    }

    for (int i = 0; i < size; i++)
    {
        quantity = 0;

        for (int j = 0; j < size; j++)
        {
            if (tree[i][j] == 1 && i != j)
            {
                quantity++;
                interim_res = i * size + j;
            }
        }

        if (quantity > max_quant)
        {
            max_quant = quantity;
            res = interim_res;
        }

        if (numb_of_diag == 1 && quantity == 1)
            return interim_res;
    }

    return res;
}
