#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define N_NEGATIVE_NUMBER 6
#define N_BIG_NUMBER 7
#define THE_MAXIMUM_VALUE_OF_THE_VARIABLE_N 78

int checking_the_number_n(int n)
{
    if (n < 0)
    {
        printf("n - целое неотрицательное число!\n");
        return N_NEGATIVE_NUMBER;
    }
    if (n > THE_MAXIMUM_VALUE_OF_THE_VARIABLE_N)
    {
        printf("Введено слишком большое n!\n");
        return N_BIG_NUMBER;
    }
    else
        return OK;
}

int fibonacci(int n)
{
    int f0, f1, fn, correct_input;
    
    correct_input = checking_the_number_n(n);
    
    if (correct_input == N_NEGATIVE_NUMBER)
        return N_NEGATIVE_NUMBER;
    else if (correct_input == N_BIG_NUMBER)
        return N_BIG_NUMBER;
    
    f0 = 0;
    f1 = 1;
    fn = 0;
    
    if (n == 0)
        fn = 0;
    else if (n == 1)
        fn = 1;
    else
        for (int i = 2; i <= n; i++)
        {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
    return fn;
}

int main(void)
{
    int r, n, fn;
    printf("Введите число n: ");
    r = scanf("%d", &n);
    
    if (r != 1)
    {
        printf("Ошибка ввода!\n");
        return INPUT_ERROR;
    }

    fn = fibonacci(n);
    
    if (fn == N_NEGATIVE_NUMBER)
        return N_NEGATIVE_NUMBER;
    else if (fn == N_BIG_NUMBER)
        return N_BIG_NUMBER;
    
    printf("Fn = %d\n", fn);
    return OK;
}
