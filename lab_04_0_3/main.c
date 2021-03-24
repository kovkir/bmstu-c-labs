#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(void)
{
    char *k, str[MAX_STR_LEN + 1];
    int number_of_words;
    
    k = fgets(str, MAX_STR_LEN + 1, stdin);
    
    if (k == NULL)
    {
        printf("Ошибка при вводе строки\n");
        return ERROR_ENTERING_STRING;
    }
        
    char array_of_words[MAXIMUM_NUMBER_OF_WORDS][MAXIMUM_WORD_LENGTH + 1];
    
    number_of_words = fill_an_array_of_words(str, array_of_words);
    
    if (number_of_words == ERROR_CREATING_WORD)
        return ERROR_CREATING_WORD;
    else if (number_of_words == NEW_LINE_IS_EMPTY)
        return NEW_LINE_IS_EMPTY;
    
    char new_str[MAX_STR_LEN];
    
    fill_new_str(new_str, number_of_words, array_of_words);
    
    if (strlen(new_str) == 0)
    {
        printf("Новая строка пустая\n");
        return NEW_LINE_IS_EMPTY;
    }
    
    printf("Result: %s\n", new_str);
    
    return SUCCESS;
}
