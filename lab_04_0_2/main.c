#include "functions.h"


int main(void)
{
    char str[MAX_STR_LEN + 1];
    int k, number_of_words;
    
    k = line_input(str, MAX_STR_LEN + 1);
    
    if (k == LINE_INPUT_ERROR)
        return LINE_INPUT_ERROR;
    else if (k == EMPTY_LINE)
        return EMPTY_LINE;
    
    char array_of_words[MAXIMUM_NUMBER_OF_WORDS][MAXIMUM_WORD_LENGTH + 1];
    
    number_of_words = fill_an_array_of_words(str, array_of_words);

    if (number_of_words == MISTAKE_FILLING_OUT_THE_WORD)
        return MISTAKE_FILLING_OUT_THE_WORD;
    else if (number_of_words == NO_WORDS_IN_LINE)
        return NO_WORDS_IN_LINE;
    
    result_output(array_of_words, number_of_words);
    
    return SUCCESS;
}
