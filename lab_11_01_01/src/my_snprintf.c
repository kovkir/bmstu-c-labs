#include "../inc/my_snprintf.h"

int my_snprintf(char *buf_p, int buf_size, const char *format, ...)
{
    va_list argptr;

    va_start(argptr, format);

    char ch, *buf_end = buf_p + buf_size;
    int char_in_buf = 0;
    
    while (*format != '\0')
    {
        if (*format == '%')
        {
            if (*(format + 1) == 'c')
            {
                ch = va_arg(argptr, int);

                add_char_to_buffer(&buf_p, buf_end, ch);
                char_in_buf++;
            }
            else if (*(format + 1) == 'h' && *(format + 2) == 'd')
            {
                char_in_buf += add_number_to_buffer(argptr, &buf_p, buf_end);

                format++;
            }
            else if (*(format + 1) == 's')
            {
                char_in_buf += add_string_to_buffer(argptr, &buf_p, buf_end);
            }
            else if (*(format + 1) == 'o')
            {
                char_in_buf += add_octal_number_to_buffer(argptr, &buf_p, buf_end);
            }
            
            format++;
        }
        else
        {
            add_char_to_buffer(&buf_p, buf_end, *format);
            char_in_buf++;
        }

        format++;
    }

    if (buf_p < buf_end)
    {
        *buf_p = '\0';
    }
    else if (buf_size > 0)
    {
        *(--buf_p) = '\0';
    }
    
    va_end(argptr);
    
    return char_in_buf;
}
