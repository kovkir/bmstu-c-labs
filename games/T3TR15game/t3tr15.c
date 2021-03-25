#include <stdio.h>

#define ROWS 20
#define COLS 10

void fill_array(char **bf, int *array)
{
    for (int j = 0; j < COLS; j++)
    {
        array[j] = -1;

        for (int i = 0; i < ROWS; i++)
        {
            if (bf[i][j] == 'X')
                array[j] = i;
            else
                break;
        }
    }
}

int max_elem(int *array, int n)
{
    int max = array[0];

    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

int column_number(int *array, int n)
{
    int num_col, elem, quant, max_el;

    num_col = -1;
    max_el = -1;

    for (int i = 0; i < COLS; i++)
    {
        elem = array[i];
        quant = 1;

        for (int j = i + 1; j < COLS; j++)
        {
            if (array[j] == elem)
                quant++;
            else
                break;
        }

        if (quant >= n)
        {
            if (elem >= max_el)
            {
                num_col = i;
                max_el = elem;
            }
        }
    }

    return num_col;
}

int forced_column_number(int *array, int n)
{
    int num_col, elem, quant, max_el;

    num_col = -1;
    max_el = -1;

    for (int i = 0; i < COLS; i++)
    {
        elem = array[i];
        quant = 1;

        for (int j = i + 1; j < COLS; j++)
        {
            if (array[j] == elem)
                quant++;
            else
                break;
        }

        if (quant >= n)
        {
            if (elem >= max_el)
            {
                num_col = i;
                max_el = elem;
            }
        }
    }

    if (num_col == -1)
    {
        int max_elem_of_array = max_elem(array, COLS);

        if (max_elem_of_array < 0)
            return 0;

        for (int i = 0; i < COLS; i++)
        {
            if (array[i] == max_elem_of_array)
                array[i]--;
        }

        num_col = forced_column_number(array, n);
    }

    return num_col;
}

void fill_holes(int *array, const char figure)
{
    if (array[0] - array[1] > 1)
    {
        if (figure == 'O' || figure == 'S')
            array[0] = array[1];
        else if (figure == 'Z' || figure == 'T' || figure == 'L')
            array[0] = array[1] + 1;
        else
            array[0] = array[1] + 2;
    }

    if (array[9] - array[8] > 1)
    {
        if (figure == 'O' || figure == 'Z')
            array[9] = array[8];
        else if (figure == 'S' || figure == 'T' || figure == 'J')
            array[9] = array[8] + 1;
        else
            array[9] = array[8] + 2;
    }

    for (int i = 1; i < COLS - 1; i++)
    {
        if (array[i] - array[i - 1] > 1 && array[i] - array[i + 1] > 1)
        {
            if (array[i - 1] > array[i + 1])
            {
                if (figure == 'O')
                    array[i] = array[i - 1];
                else if (figure == 'S' || figure == 'Z' || figure == 'T')
                    array[i] = array[i - 1] + 1;
                else
                    array[i] = array[i - 1] + 2;
            }
            else
            {
                if (figure == 'O')
                    array[i] = array[i + 1];
                else if (figure == 'S' || figure == 'Z' || figure == 'T')
                    array[i] = array[i + 1] + 1;
                else
                    array[i] = array[i + 1] + 2;
            }
            
        }
    }
}

int tetris_game(char **bf, const char figure, int *const angle)
{
    int array[COLS];

    fill_array(bf, array);

    if (figure != 'I')
        fill_holes(array, figure);

    int numb_col;

    if (figure == 'I')
    {
        numb_col = column_number(array, 1);

        if (numb_col != -1 && array[numb_col] >= 3)
        {
            *angle = 0;
            return numb_col;
        }  
        
        numb_col = column_number(array, 4);

        if (numb_col != -1 && array[numb_col] != -1)
        {
            *angle = 3;
            return numb_col;
        }

        *angle = 3;
        numb_col = forced_column_number(array, 4);

        return numb_col;
    }
    else if (figure == 'O')
    {
        numb_col = column_number(array, 2);

        if (numb_col != -1 && array[numb_col] >= 1)
            return numb_col;

        if (array[numb_col] < 1)
            array[numb_col] = -1;

        numb_col = forced_column_number(array, 2);

        return numb_col;
    }
    else if (figure == 'S')
    {
        numb_col = column_number(array, 1);

        if (numb_col != -1 && array[numb_col] >= 2)
        {
            if (numb_col != 0 && array[numb_col] - array[numb_col - 1] == 1)
            {
                *angle = 3;
                return numb_col - 1;
            }
        }


        numb_col = column_number(array, 2);

        if (numb_col != -1 && array[numb_col] >= 1)
        {
            if (numb_col < 8 && array[numb_col] - array[numb_col + 2] == 1)
            {
                *angle = 0;
                return numb_col;
            }
        }  

        for (int i = 0, number; i < COLS - 2; i++)
        {
            number = array[i];

            if (number < 1)
                continue;

            if (array[i + 1] == number && array[i + 2] == number - 1)
            {
                *angle = 0;
                return i;
            }
        }

        for (int i = 1, number; i < COLS; i++)
        {
            number = array[i];

            if (number < 2)
                continue;

            if (array[i - 1] == number - 1)
            {
                *angle = 3;
                return i - 1;
            }
        }

        int array_copy[COLS];

        for (int i = 0; i < COLS; i++)
            array_copy[i] = array[i];

        numb_col = forced_column_number(array_copy, 3);

        if (array[numb_col] >= 1)
        {
            *angle = 0;
            return numb_col;
        }  

        numb_col = forced_column_number(array, 2);

        if (array[numb_col] >= 2)
        {
            *angle = 3;
            return numb_col;
        }
        
        array[numb_col] = -1;

        numb_col = forced_column_number(array, 2);
        *angle = 3;

        return numb_col;
    }
    else if (figure == 'Z')
    {
        numb_col = column_number(array, 1);

        if (numb_col != -1 && array[numb_col] >= 2)
        {
            if (numb_col != 9 && array[numb_col] - array[numb_col + 1] == 1)
            {
                *angle = 3;
                return numb_col;
            }
        }

        numb_col = column_number(array, 2);

        if (numb_col != -1 && array[numb_col] >= 1)
        {
            if (numb_col < 9 && array[numb_col] - array[numb_col - 1] == 1)
            {
                *angle = 0;
                return numb_col - 1;
            }
        }  

        for (int i = 0, number; i < COLS - 2; i++)
        {
            number = array[i];

            if (number < 0)
                continue;

            if (array[i + 1] == number + 1 && array[i + 2] == number + 1)
            {
                *angle = 0;
                return i;
            }
        }

        for (int i = 0, number; i < COLS - 1; i++)
        {
            number = array[i];

            if (number < 2)
                continue;

            if (array[i + 1] == number - 1)
            {
                *angle = 3;
                return i;
            }
        }
        
        int array_copy[COLS];

        for (int i = 0; i < COLS; i++)
            array_copy[i] = array[i];

        numb_col = forced_column_number(array_copy, 3);

        if (array[numb_col] >= 1)
        {
            *angle = 0;
            return numb_col;
        }  

        numb_col = forced_column_number(array, 2);

        if (array[numb_col] >= 2)
        {
            *angle = 3;
            return numb_col;
        }
        
        array[numb_col] = -1;

        numb_col = forced_column_number(array, 2);
        *angle = 3;
        
        return numb_col;
    }
    else if (figure == 'L')
    {
        numb_col = column_number(array, 1);

        if (numb_col != -1 && array[numb_col] >= 2)
        {
            if (numb_col != 0 && array[numb_col] - array[numb_col - 1] == 2)
            {
                *angle = 6;
                return numb_col - 1;
            }
        }

        if (numb_col != -1 && array[numb_col] >= 1)
        {
            if (numb_col < 8 && array[numb_col] - array[numb_col + 1] == 1
                             && array[numb_col] - array[numb_col + 2] == 1)
            {
                *angle = 3;
                return numb_col;
            }
        }

        for (int i = 0, number; i < COLS - 1; i++)
        {
            number = array[i];

            if (number < 0)
                continue;

            if (array[i + 1] == number + 2)
            {
                *angle = 6;
                return i;
            }
        }

        for (int i = 0, number; i < COLS - 2; i++)
        {
            number = array[i];

            if (number < 1)
                continue;

            if (array[i + 1] == number - 1 && array[i + 2] == number - 1)
            {
                *angle = 3;
                return i;
            }
        }

        numb_col = column_number(array, 3);

        if (numb_col != -1 && array[numb_col] >= 1)
        {
            *angle = 9;
            return numb_col;
        }  

        numb_col = column_number(array, 2);

        if (numb_col != -1 && array[numb_col] >= 2)
        {
            *angle = 0;
            return numb_col;
        }

        int array_copy[COLS];

        for (int i = 0; i < COLS; i++)
            array_copy[i] = array[i];

        numb_col = forced_column_number(array_copy, 3);

        if (array[numb_col] >= 1)
        {
            *angle = 9;
            return numb_col;
        }  

        numb_col = forced_column_number(array, 2);

        if (array[numb_col] >= 2)
        {
            *angle = 0;
            return numb_col;
        }
        
        array[numb_col] = -1;

        numb_col = forced_column_number(array, 2);
        *angle = 0;
        
        return numb_col;
    }
    else if (figure == 'J')
    {
        numb_col = column_number(array, 1);

        if (numb_col != -1 && array[numb_col] >= 2)
        {
            if (numb_col != 9 && array[numb_col] - array[numb_col + 1] == 2)
            {
                *angle = 6;
                return numb_col;
            }
        }

        if (numb_col != -1 && array[numb_col] >= 1)
        {
            if (numb_col > 1 && array[numb_col] - array[numb_col - 1] == 1
                             && array[numb_col] - array[numb_col - 2] == 1)
            {
                *angle = 9;
                return numb_col - 2;
            }
        }

        for (int i = 0, number; i < COLS - 1; i++)
        {
            number = array[i];

            if (number < 2)
                continue;

            if (array[i + 1] == number - 2)
            {
                *angle = 6;
                return i;
            }
        }

        for (int i = 2, number; i < COLS; i++)
        {
            number = array[i];

            if (number < 1)
                continue;

            if (array[i - 1] == number - 1 && array[i - 2] == number - 1)
            {
                *angle = 9;
                return i - 2;
            }
        }

        numb_col = column_number(array, 3);

        if (numb_col != -1 && array[numb_col] >= 1)
        {
            *angle = 3;
            return numb_col;
        }  

        numb_col = column_number(array, 2);

        if (numb_col != -1 && array[numb_col] >= 2)
        {
            *angle = 0;
            return numb_col;
        }

        int array_copy[COLS];

        for (int i = 0; i < COLS; i++)
            array_copy[i] = array[i];

        numb_col = forced_column_number(array_copy, 3);

        if (array[numb_col] >= 1)
        {
            *angle = 3;
            return numb_col;
        }  

        numb_col = forced_column_number(array, 2);

        if (array[numb_col] >= 2)
        {
            *angle = 0;
            return numb_col;
        }
        
        array[numb_col] = -1;

        numb_col = forced_column_number(array, 2);
        *angle = 0;
        
        return numb_col;
    }
    else if (figure == 'T')
    {
        for (int i = 1, number; i < COLS - 1; i++)
        {
            number = array[i];

            if (number < 1)
                continue;

            if (array[i + 1] == number - 1 && array[i - 1] == number - 1)
            {
                *angle = 0;
                return i - 1;
            }
        }

        for (int i = 0, number; i < COLS - 1; i++)
        {
            number = array[i];

            if (number < 1)
                continue;

            if (array[i + 1] == number + 1)
            {
                *angle = 3;
                return i;
            }
        }

        for (int i = 1, number; i < COLS; i++)
        {
            number = array[i];

            if (number < 1)
                continue;

            if (array[i - 1] == number + 1)
            {
                *angle = 9;
                return i - 1;
            }
        }

        int array_copy[COLS];

        for (int i = 0; i < COLS; i++)
            array_copy[i] = array[i];

        numb_col = forced_column_number(array_copy, 3);

        if (array[numb_col] >= 1)
        {
            *angle = 6;
            return numb_col;
        }  

        numb_col = forced_column_number(array, 2);

        if (array[numb_col] >= 2)
        {
            *angle = 3;
            return numb_col;
        }
        
        array[numb_col] = -1;

        numb_col = forced_column_number(array, 2);
        *angle = 3;

        return numb_col;
    }

    return 0;
}