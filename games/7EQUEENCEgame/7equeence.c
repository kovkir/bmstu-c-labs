long long sequence_game(int array[])
{
    long long number, number0;
    number = 1;

    for (int i = 0; i < 13; i++)
        number *= array[i];
        
    number0 = number;

    for (int i = 13; i < 1000; i++)
    {
        number0 = number0 * array[i] / array[i - 13];

        if (number0 > number)
            number = number0;
    }

    return number;
}