#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define MATRIX_FILLING_ERROR 2
#define NO_PRIME_NUMBERS 3

#define YES 0
#define NO 1
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

int prime_number(const int number)
{
    int i = 2;
    
    if (number == 1)
        return NO;
    
    while (i < number)
    {
        if (number % i == 0)
            return NO;
        
        i++;
    }
    
    return YES;
}

int array_filling(int array[], int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    int y = 0;
    
    for (int i = 0; i < number_of_lines; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            if (prime_number(matrix[i][j]) == YES)
            {
                array[y] = matrix[i][j];
                y++;
            }
        }
    }
    
    return y;
}

void reverse_array(int array[], const int number_of_element)
{
    int c;
    
    for (int i = 0; i < number_of_element / 2; i++)
    {
        c = array[i];
        array[i] = array[number_of_element - 1 - i];
        array[number_of_element - 1 - i] = c;
    }
}

void matrix_processing(int array[], int matrix[][MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    int y = 0;
    
    for (int i = 0; i < number_of_lines; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            if (prime_number(matrix[i][j]) == YES)
            {
                matrix[i][j] = array[y];
                y++;
            }
        }
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

    int array[MAXIMUM_NUMBER_OF_ELEMENTS * MAXIMUM_NUMBER_OF_ELEMENTS];
    int number_of_element;
    
    number_of_element = array_filling(array, matrix, number_of_lines, number_of_columns);
    
    if (number_of_element == 0)
    {
        printf("В матрице нет простых чисел\n");
        return NO_PRIME_NUMBERS;
    }
    
    reverse_array(array, number_of_element);
    matrix_processing(array, matrix, number_of_lines, number_of_columns);
    print_matrix(matrix, number_of_lines, number_of_columns);

    return OK;
}
