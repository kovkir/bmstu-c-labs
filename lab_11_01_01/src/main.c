#include "../inc/main.h"

int main(void)
{
    char buf1[SIZE_BUF + 1];
    char buf2[SIZE_BUF + 1];

    char string[] = "world";
    short int number = 123;
    int octal_number = 66;

    int n1 = my_snprintf(buf1, SIZE_BUF, "%c Hello %hd %s k %o ", 'a', number, string, octal_number);
    int n2 = snprintf(buf2, SIZE_BUF, "%c Hello %hd %s k %o ", 'a', number, string, octal_number);

    printf("%d, %s\n", n1, buf1);
    printf("%d, %s\n", n2, buf2);

    return SUCCESS;
}
