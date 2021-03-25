#include <stdio.h>

int number_of_letters_near(int i, int j, char **bf, char letter, const int size)
{
    int quantiy = 0;

    if (i == 0 && j == 0)
    {
        if (bf[i][j + 1] == letter)
            quantiy++;

        if (bf[i + 1][j] == letter)
            quantiy++;

        if (bf[i + 1][j + 1] == letter)
            quantiy++;
    }
    else if (i == 0 && j == size - 1)
    {
        if (bf[i][j - 1] == letter)
            quantiy++;

        if (bf[i + 1][j] == letter)
            quantiy++;

        if (bf[i + 1][j - 1] == letter)
            quantiy++;
    }
    else if (i == size - 1 && j == 0)
    {
        if (bf[i][j + 1] == letter)
            quantiy++;

        if (bf[i - 1][j] == letter)
            quantiy++;

        if (bf[i - 1][j + 1] == letter)
            quantiy++;
    }
    else if (i == size - 1 && j == size - 1)
    {
        if (bf[i][j - 1] == letter)
            quantiy++;

        if (bf[i - 1][j] == letter)
            quantiy++;

        if (bf[i - 1][j - 1] == letter)
            quantiy++;
    }
    else if (i == 0)
    {
        if (bf[i][j + 1] == letter)
            quantiy++;

        if (bf[i][j - 1] == letter)
            quantiy++;
        
        if (bf[i + 1][j + 1] == letter)
            quantiy++;

        if (bf[i + 1][j - 1] == letter)
            quantiy++;

        if (bf[i + 1][j] == letter)
            quantiy++;
    }
    else if (i == size - 1)
    {
        if (bf[i][j + 1] == letter)
            quantiy++;

        if (bf[i][j - 1] == letter)
            quantiy++;
        
        if (bf[i - 1][j + 1] == letter)
            quantiy++;

        if (bf[i - 1][j - 1] == letter)
            quantiy++;

        if (bf[i - 1][j] == letter)
            quantiy++;
    }
    else if (j == 0)
    {
        if (bf[i + 1][j] == letter)
            quantiy++;

        if (bf[i - 1][j] == letter)
            quantiy++;
        
        if (bf[i + 1][j + 1] == letter)
            quantiy++;

        if (bf[i - 1][j + 1] == letter)
            quantiy++;

        if (bf[i][j + 1] == letter)
            quantiy++;
    }
    else if (j == size - 1)
    {
        if (bf[i + 1][j] == letter)
            quantiy++;

        if (bf[i - 1][j] == letter)
            quantiy++;
        
        if (bf[i + 1][j - 1] == letter)
            quantiy++;

        if (bf[i - 1][j - 1] == letter)
            quantiy++;

        if (bf[i][j - 1] == letter)
            quantiy++;
    }
    else
    {
        if (bf[i][j + 1] == letter)
            quantiy++;

        if (bf[i + 1][j] == letter)
            quantiy++;

        if (bf[i + 1][j + 1] == letter)
            quantiy++;

        if (bf[i][j - 1] == letter)
            quantiy++;

        if (bf[i - 1][j] == letter)
            quantiy++;

        if (bf[i - 1][j - 1] == letter)
            quantiy++;

        if (bf[i + 1][j - 1] == letter)
            quantiy++;

        if (bf[i - 1][j + 1] == letter)
            quantiy++;
    }
    
    return quantiy;
}

int reagent_game(char **bf, const int size)
{   
    int max_b = -1, ret = 0, max_a = -1, quant = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bf[i][j] == 'B')
            {
                quant = number_of_letters_near(i, j, bf, 'B', size);

                if (quant > max_b)
                {
                    max_b = quant;
                    ret = i * size + j;

                    quant = number_of_letters_near(i, j, bf, 'A', size);
                    max_a = quant;
                }
                else if (quant == max_b)
                {
                    quant = number_of_letters_near(i, j, bf, 'A', size);

                    if (quant > max_a)
                    {
                        max_a = quant;
                        ret = i * size + j;
                    }
                }
            }
        }
    }

    if (max_b > -1)
        return ret;

    max_a = -1;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bf[i][j] == 'A')
            {
                quant = number_of_letters_near(i, j, bf, 'A', size);

                if (quant > max_a)
                {
                    max_a = quant;
                    ret = i * size + j;
                }
            }
        }
    }

    return ret;
}
