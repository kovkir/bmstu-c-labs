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

int kol_elem_in_new_array(int array[], const int kol_elem, double *arithmetical_mean)
{
    int sum, kol;
    sum = 0;
    kol = 0;
    for (int i = 0; i < kol_elem; i++)
        sum += array[i];
    *arithmetical_mean = sum / kol_elem;
    for (int i = 0; i < kol_elem; i++)
    {
        if (array[i] > *arithmetical_mean)
            kol++;
    }
    
    if (kol == 0)
    {
        return NEW_ARRAY_IS_EMPTY;
    }
    
    return kol;
}

void new_array_filling(int array[], int kol_elem, int new_array[],
int new_kol_elem, double *arithmetical_mean)
{
    int j = 0;
    for (int i = 0; i < kol_elem; i++)
    {
        if (array[i] > *arithmetical_mean)
        {
            new_array[j] = array[i];
            j++;
        }
    }
}

void print_array(int array[], int kol_elem)
{
    for (int i = 0; i < kol_elem; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int kol_elem, new_kol_elem, r, k;
    double arithmetical_mean;
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
    
    new_kol_elem = kol_elem_in_new_array(array, kol_elem, &arithmetical_mean);
    
    if (new_kol_elem == NEW_ARRAY_IS_EMPTY)
    {
        printf("Новый массив пуст\n");
        return NEW_ARRAY_IS_EMPTY;
    }
    
    int new_array[MAXIMUM_NUMBER_OF_ELEMENTS];
    new_array_filling(array, kol_elem, new_array, new_kol_elem, &arithmetical_mean);
    printf("Новый массив:\n");
    print_array(new_array, new_kol_elem);
    
    return OK;
}
