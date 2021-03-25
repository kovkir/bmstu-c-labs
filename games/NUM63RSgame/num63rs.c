int numbers_game(int min, int max)
{
    int number, max1;

    if (min == max)
        return max;
        
    number = 0;
    max1 = max * (max - 1);
    max -= 2;

    do
    {
        number += max1;
        for (int i = max; i >= min; i--)
        {
            if (number % i == 0)
            {
                max1 = number;
                max -= 1;
            }
            else
            {
                if ((i % 2 == 0) || (i % 3 == 0))
                    break;

                max1 = number * i;
                number = 0;
                max -= 1;
                break;
            }
        }
        
    }
    while (max >= min);

    if (number == 0)
        number += max1;

    return number;
}