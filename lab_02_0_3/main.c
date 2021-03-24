#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define ARRAY_FILLING_ERROR 2
#define NEW_ARRAY_IS_EMPTY -1

#define MAXIMUM_NUMBER_OF_ELEMENTS 10

int array_filling(int array[], const int kol_elem)
{
    int r1;
    printf("Заполните массив\n");
    for (int i = 0; i < kol_elem; i++)
    {
        r1 = scanf("%d", &array[i]);
        
        if (r1 != 1)
            return ARRAY_FILLING_ERROR;
    }
    return OK;
}

int number_of_palindrome_numbers(int array[], const int kol_elem)
{
    int kol, a, b;
    kol = 0;
    for (int i = 0; i < kol_elem; i++)
    {
        b = 0;
        a = array[i];
        while (a > 0)
        {
            b = b * 10 + a % 10;
            a /= 10;
        }
        if (b == array[i])
        {
            array[i] = 1;
            kol++;
        }
    }
    return kol;
}

void new_array_filling(const int array[], const int kol_elem,
int new_array[], const int new_kol_elem)
{
    int j = 0;
    for (int i = 0; i < kol_elem; i++)
    {
        if (array[i] != 1)
        {
            new_array[j] = array[i];
            j++;
        }
    }
}

void print_array(const int array[], const int kol_elem)
{
    printf("Новый массив:\n");
    
    for (int i = 0; i < kol_elem; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int array_without_palindrome_numb(int array[], const int kol_elem)
{
    int new_kol_elem;
    new_kol_elem = kol_elem - number_of_palindrome_numbers(array, kol_elem);
    
    if (new_kol_elem == 0)
        return NEW_ARRAY_IS_EMPTY;
    
    int new_array[MAXIMUM_NUMBER_OF_ELEMENTS];
    new_array_filling(array, kol_elem, new_array, new_kol_elem);
    
    for (int i = 0; i < new_kol_elem; i++)
        array[i] = new_array[i];
    
    return new_kol_elem;
}

int main(void)
{
    int kol_elem, new_kol_elem, r, k;
    printf("Введите кол-во элементов в массиве ");
    r = scanf("%d", &kol_elem);
    
    if ((r != 1) || (kol_elem > MAXIMUM_NUMBER_OF_ELEMENTS) || (kol_elem <= 0))
    {
        printf("Ошибка ввода\n");
        return INPUT_ERROR;
    }
    
    int array[MAXIMUM_NUMBER_OF_ELEMENTS];
    k = array_filling(array, kol_elem);
    
    if (k == ARRAY_FILLING_ERROR)
    {
        printf("Ошибка при заполнении массива\n");
        return ARRAY_FILLING_ERROR;
    }
    
    new_kol_elem = array_without_palindrome_numb(array, kol_elem);
    
    if (new_kol_elem == NEW_ARRAY_IS_EMPTY)
    {
        printf("Новый массив пуст\n");
        return NEW_ARRAY_IS_EMPTY;
    }
    
    print_array(array, new_kol_elem);
    
    return OK;
}
