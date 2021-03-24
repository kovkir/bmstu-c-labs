#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define ARRAY_FILLING_ERROR 2

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

void array_sorting(int array[], const int kol_elem)
{
    int num_min, c;
    for (int i = 0; i < kol_elem; i++)
    {
        num_min = i;
        for (int j = i + 1; j < kol_elem; j++)
        {
            if (array[j] < array[num_min])
                num_min = j;
        }
        c = array[num_min];
        array[num_min] = array[i];
        array[i] = c;
    }
}

void print_array(int array[], const int kol_elem)
{
    for (int i = 0; i < kol_elem; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int kol_elem, r, k;
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
    
    array_sorting(array, kol_elem);
    printf("Отсортированный массив:\n");
    print_array(array, kol_elem);
    
    return OK;
}
