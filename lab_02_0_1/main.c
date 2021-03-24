#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define ARRAY_FILLING_ERROR 2
#define NO_EVEN_ELEMENTS 3

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

int sum_of_even_elements(int a[], const int kol_elem)
{
    int sum, kol;
    sum = 0;
    kol = 0;
    for (int i = 0; i < kol_elem; i++)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
            kol += 1;
        }
    }
    
    if (kol == 0)
        return NO_EVEN_ELEMENTS;
    
    return sum;
}

int main(void)
{
    int kol_elem, sum, r, k;
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
    sum = sum_of_even_elements(array, kol_elem);
    
    if (sum == NO_EVEN_ELEMENTS)
    {
        printf("В массиве нет чётных элементов\n");
        return NO_EVEN_ELEMENTS;
    }
    printf("Сумма чётных элементов массива равна %d\n", sum);
    return OK;
}
