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

int array_element_value(int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int j)
{
    if (number_of_lines == 1)
        return 0;
    
    for (int i = 1; i < number_of_lines; i++)
    {
        if (matrix[i][j] >= matrix[i - 1][j])
            return 0;
    }
    return 1;
}

void array_filing(int array[], int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    for (int j = 0; j < number_of_columns; j++)
    {
        array[j] = array_element_value(matrix, number_of_lines, j);
    }
}

void print_array(int array[], const int number_of_columns)
{
    printf("Образованный массив:\n");
    for (int i = 0; i < number_of_columns; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
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
    array_filing(array, matrix, number_of_lines, number_of_columns);
    print_array(array, number_of_columns);

    return OK;
}
