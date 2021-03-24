#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define MATRIX_FILLING_ERROR 2

#define MAXIMUM_NUMBER_OF_ELEMENTS 10

int matrix_filling(int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    int r1;
    printf("Заполните матрицу\n");
    for (int i = 0; i < number_of_lines; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            r1 = scanf("%d", &matrix[i][j]);
        
            if (r1 != 1)
                return MATRIX_FILLING_ERROR;
        }
    }
    return OK;
}

void array_filling(int array[], int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    for (int i = 0; i < number_of_lines; i++)
    {
        array[i] = 0;
        
        for (int j = 0; j < number_of_columns; j++)
            array[i] += matrix[i][j];
    }
}

void string_replacement(int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_columns, const int i_1, const int i_2)
{
    int c;
    
    for (int j = 0; j < number_of_columns; j++)
    {
        c = matrix[i_1][j];
        matrix[i_1][j] = matrix[i_2][j];
        matrix[i_2][j] = c;
    }
}

void sorting_matrix_rows(int array[], int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    int minimum, i_minimum, c;

    for (int i = 0; i < number_of_lines; i++)
    {
        minimum = array[i];
        i_minimum = i;
        
        for (int j = i + 1; j < number_of_lines; j++)
        {
            if (array[j] < minimum)
            {
                minimum = array[j];
                i_minimum = j;
            }
        }
        
        c = array[i];
        array[i] = array[i_minimum];
        array[i_minimum] = c;
        string_replacement(matrix, number_of_columns, i, i_minimum);
    }
}

void print_matrix(int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    printf("Обработанная матрица:\n");
    for (int i = 0; i < number_of_lines; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int number_of_lines, number_of_columns, r, k;
    
    printf("Введите кол-во строк и столбцов в матрице: ");
    r = scanf("%d %d", &number_of_lines, &number_of_columns);
    
    if ((r != 2) || (number_of_lines > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (number_of_lines <= 0) || (number_of_columns > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (number_of_columns <= 0))
    {
        printf("Ошибка ввода\n");
        return INPUT_ERROR;
    }
    
    int matrix[MAXIMUM_NUMBER_OF_ELEMENTS][MAXIMUM_NUMBER_OF_ELEMENTS];
    k = matrix_filling(matrix, number_of_lines, number_of_columns);
    
    if (k == MATRIX_FILLING_ERROR)
    {
        printf("Ошибка при заполнении матрицы\n");
        return MATRIX_FILLING_ERROR;
    }

    int array[MAXIMUM_NUMBER_OF_ELEMENTS];

    array_filling(array, matrix, number_of_lines, number_of_columns);
    sorting_matrix_rows(array, matrix, number_of_lines, number_of_columns);
    print_matrix(matrix, number_of_lines, number_of_columns);
    
    return OK;
}
