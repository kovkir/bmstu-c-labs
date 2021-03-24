#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define ARRAY_FILLING_ERROR 2

#define MAXIMUM_NUMBER_OF_ELEMENTS 10
#define MINIMUM_NUMBER_OF_ELEMENTS 2

int array_filling(int *pnach, int *pkon)
{
    int r1, *pa;
    pa = pnach;
    printf("Заполните массив\n");
    while (pa < pkon)
    {
        r1 = scanf("%d", pa);
        
        if (r1 != 1)
            return ARRAY_FILLING_ERROR;
        pa++;
    }
    return OK;
}

int array_processing(int *pnach, int *pkon)
{
    int min, b, *pa;
    min = *pnach * *(pnach + 1);
    pa = pnach + 2;
    while (pa < pkon)
    {
        b = *pa * *(pa - 1);
        
        if (b < min)
            min = b;
        pa++;
    }
    return min;
}

int main(void)
{
    int kol_elem, r, k, min;
    printf("Введите кол-во элементов в массиве ");
    r = scanf("%d", &kol_elem);
    
    if ((r != 1) || (kol_elem > MAXIMUM_NUMBER_OF_ELEMENTS) ||
        (kol_elem < MINIMUM_NUMBER_OF_ELEMENTS))
    {
        printf("Ошибка ввода\n");
        return INPUT_ERROR;
    }
    
    int array[MAXIMUM_NUMBER_OF_ELEMENTS];
    k = array_filling(array, array + kol_elem);
    
    if (k == ARRAY_FILLING_ERROR)
    {
        printf("Ошибка при заполнении массива\n");
        return ARRAY_FILLING_ERROR;
    }
    
    min = array_processing(array, array + kol_elem);
    printf("min = %d\n", min);
    
    return OK;
}
