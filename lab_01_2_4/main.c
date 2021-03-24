#include <stdio.h>

#define OK 0
#define NUMBER_OF_SECONDS_IN_MINUTE 60
#define NUMBER_OF_MINUTE_IN_HOUR 60

int main(void)
{
    int sec, min, hour;
    printf("Введите кол-во секунд: \n");
    scanf("%d", &sec);
    min = sec / NUMBER_OF_SECONDS_IN_MINUTE;
    sec %= NUMBER_OF_SECONDS_IN_MINUTE;
    hour = min / NUMBER_OF_MINUTE_IN_HOUR;
    min %= NUMBER_OF_MINUTE_IN_HOUR;
    printf("%d час(а,ов), %d минут(a,ы), %d секунд(а,ы)\n",
    hour, min, sec);
    return OK;
}
