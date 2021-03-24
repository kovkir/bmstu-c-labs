#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERROR 1
#define MATRIX_FILLING_ERROR 2
#define INPUT_NUMERAL_ERROR 3

#define MAXIMUM_NUMBER_OF_ELEMENTS 10
#define YES 0
#define NO 1

int matrix_filling(int matrix[][2 * MAXIMUM_NUMBER_OF_ELEMENTS],
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

int line_check(int array[], const int number_of_columns, const int numeral)
{
    int kol_start, kol_end, b;
    
    kol_start = 0;
    kol_end = 0;
    
    for (int i = 0; i < number_of_columns; i++)
    {
        b = abs(array[i]);
        
        while (b > 9)
            b /= 10;
        
        if (b == numeral)
            kol_start++;
        
        if (abs(array[i] % 10) == numeral)
            kol_end++;
    }
    
    if ((kol_start == kol_end) && (kol_start != 0))
        return YES;
    else
        return NO;
}

int matrix_change(int matrix[][2 * MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns, const int numeral)
{
    int kol, i;
    kol = 0;
    i = 0;
    
    while (i < kol + number_of_lines)
    {
        if (line_check(matrix[i], number_of_columns, numeral) == YES)
        {
            for (int j = number_of_lines + kol; j > i; j--)
                for (int y = 0; y < number_of_columns; y++)
                    matrix[j][y] = matrix[j - 1][y];
            
            for (int j = 0; j < number_of_columns; j++)
                matrix[i + 1][j] = 100;
            
            i++;
            kol++;
        }
        
        i++;
    }
    
    return kol;
}

void print_matrix(int matrix[][2 * MAXIMUM_NUMBER_OF_ELEMENTS],
const int number_of_lines, const int number_of_columns)
{
    printf("\nОбработанная матрица:\n");
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
    int number_of_lines, number_of_columns, numeral, r, k;
    
    printf("Введите кол-во строк и столбцов в матрице: ");
    r = scanf("%d %d", &number_of_lines, &number_of_columns);
    
    if ((r != 2) || (number_of_lines > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (number_of_lines <= 0) || (number_of_columns > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (number_of_columns <= 0))
    {
        printf("Ошибка ввода\n");
        return INPUT_ERROR;
    }
    
    int matrix[2 * MAXIMUM_NUMBER_OF_ELEMENTS][2 * MAXIMUM_NUMBER_OF_ELEMENTS];
    k = matrix_filling(matrix, number_of_lines, number_of_columns);
    
    if (k == MATRIX_FILLING_ERROR)
    {
        printf("Ошибка при заполнении матрицы\n");
        return MATRIX_FILLING_ERROR;
    }
    
    printf("Введите цифру: ");
    r = scanf("%d", &numeral);
    
    if ((r != 1) || (numeral < 0) || (numeral > 9))
    {
        printf("Ошибка ввода цифры\n");
        return INPUT_NUMERAL_ERROR;
    }
    
    number_of_lines += matrix_change(matrix, number_of_lines, number_of_columns, numeral);
    print_matrix(matrix, number_of_lines, number_of_columns);

    return OK;
}
