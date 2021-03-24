#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define MATRIX_FILLING_ERROR 2
#define MATRIX_IS_NOT_SQUARE 3
#define NO_NUMBERS_FOUND 4

#define MAXIMUM_NUMBER_OF_ELEMENTS 10

int matrix_filling(int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_elements)
{
    int r1;
    printf("Заполните матрицу\n");
    for (int i = 0; i < number_of_elements; i++)
    {
        for (int j = 0; j < number_of_elements; j++)
        {
            r1 = scanf("%d", &matrix[i][j]);
        
            if (r1 != 1)
                return MATRIX_FILLING_ERROR;
        }
    }
    return OK;
}

int number_search(int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_elements)
{
    int minimum_odd_number;
    
    minimum_odd_number = 2;
    
    for (int i = 0; i < number_of_elements; i++)
    {
        for (int j = 0; j < number_of_elements; j++)
        {
            if ((i > j) && (matrix[i][j] % 2 != 0) && ((minimum_odd_number == 2) ||
                (matrix[i][j] < minimum_odd_number)))
            {
                minimum_odd_number = matrix[i][j];
            }
        }
    }
    
    return minimum_odd_number;
}

int main(void)
{
    int number_of_lines, number_of_columns, r, k, minimum_odd_number;
    
    printf("Введите кол-во строк и столбцов в матрице: ");
    r = scanf("%d %d", &number_of_lines, &number_of_columns);
    
    if ((r != 2) || (number_of_lines > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (number_of_lines <= 0) || (number_of_columns > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (number_of_columns <= 0))
    {
        printf("Ошибка ввода\n");
        return INPUT_ERROR;
    }
    
    if (number_of_lines != number_of_columns)
    {
        printf("Матрица должна быть квадратной\n");
        return MATRIX_IS_NOT_SQUARE;
    }
    
    int matrix[MAXIMUM_NUMBER_OF_ELEMENTS][MAXIMUM_NUMBER_OF_ELEMENTS];
    k = matrix_filling(matrix, number_of_lines);
    
    if (k == MATRIX_FILLING_ERROR)
    {
        printf("Ошибка при заполнении матрицы\n");
        return MATRIX_FILLING_ERROR;
    }

    minimum_odd_number = number_search(matrix, number_of_lines);
    
    if (minimum_odd_number == 2)
    {
        printf("Таких чисел нет\n");
        return NO_NUMBERS_FOUND;
    }
    else
        printf("\nМинимальное нечетное число, \
расположенное под главной диагональю, равно  %d\n", minimum_odd_number);
    
    return OK;
}
