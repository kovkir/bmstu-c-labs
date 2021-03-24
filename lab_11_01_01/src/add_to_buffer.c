#include "../inc/add_to_buffer.h"

char char_in_number(int number, int i)
{
    while (number >= pow(10, i))
        number /= 10;
    
    return number % 10 + '0';
}

int number_length(int number)
{
    int digits = 1;

    while (number > 9)
    {
        number /= 10;
        digits++;
    }

    return digits;
}

void add_char_to_buffer(char **buf_p, char *buf_end, char ch)
{
    if (*buf_p < buf_end)
        *((*buf_p)++) = ch;
}

int add_number_to_buffer(va_list argptr, char **buf_p, char *buf_end)
{
    int char_in_buf = 0;
    char ch;

    int number = va_arg(argptr, int);

    if (number < 0)
    {
        number *= -1;

        add_char_to_buffer(buf_p, buf_end, '-');
        char_in_buf++;
    }

    int numb_len = number_length(number);

    for (int i = 1; i <= numb_len; i++)
    {
        ch = char_in_number(number, i);

        LOG_DEBUG("%c", ch);

        add_char_to_buffer(buf_p, buf_end, ch);
        char_in_buf++;
    }

    return char_in_buf;
}

int add_string_to_buffer(va_list argptr, char **buf_p, char *buf_end)
{
    int char_in_buf = 0;

    char *str = va_arg(argptr, char*);

    for (int i = 0; str[i] != '\0'; i++)
    {
        LOG_DEBUG("%c", str[i]);

        add_char_to_buffer(buf_p, buf_end, str[i]);
        char_in_buf++;
    }

    return char_in_buf;
}

int conv_to_number_system(char dig_array[], unsigned number, int system)
{
    int i = 0;

    while (number >= system)
    {
        dig_array[i++] = number % system + '0';
        number = number / system;
    }

    dig_array[i++] = number % system + '0';

    return i;
}

int add_octal_number_to_buffer(va_list argptr, char **buf_p, char *buf_end)
{
    int char_in_buf = 0;
    char dig_array[MAX_DIGITS_IN_NUMBER + 1];

    unsigned number = va_arg(argptr, unsigned);

    int dig_in_number = conv_to_number_system(dig_array, number, 8);

    printf("%d\n", dig_in_number);

    for (int i = dig_in_number - 1; i >= 0; i--)
    {
        add_char_to_buffer(buf_p, buf_end, dig_array[i]);
        char_in_buf++;
    }
    
    return char_in_buf;
}
