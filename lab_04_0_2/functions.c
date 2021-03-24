#include <stdio.h>
#include "functions.h"

int line_input(char str[], const int line_length)
{
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n')
    {
        if ((i < line_length - 1) && (ch != EOF))
            str[i] = ch;
        else
        {
            printf("Превышена максимальная длина строки\n");
            return LINE_INPUT_ERROR;
        }
        i++;
    }
    
    if (i == 0)
    {
        printf("Введена пустая строка\n");
        return EMPTY_LINE;
    }
    else
        str[i] = '\0';
    
    return SUCCESS;
}

int punctuation_or_space(char *symbol)
{
    const char delimiters[] = " ,;:-.!?";
    
    for (int i = 0; delimiters[i] != '\0'; i++)
    {
        if (*symbol == delimiters[i])
            return YES;
    }
    
    return NO;
}

int fill_an_array_of_words(char str[],
char array_of_words[][MAXIMUM_WORD_LENGTH + 1])
{
    int j = 0, y = 0;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (punctuation_or_space(&str[i]) == YES)
        {
            if (y != 0)
            {
                array_of_words[j][y] = '\0';
                y = 0;
                j++;
            }
        }
        else
        {
            if (y == MAXIMUM_WORD_LENGTH)
            {
                printf("Ошибка при заполнении слова\n");
                return MISTAKE_FILLING_OUT_THE_WORD;
            }
            else
            {
                array_of_words[j][y] = str[i];
                y++;
            }
        }
    }

    if ((j == 0) && (y == 0))
    {
        printf("В строке нет слов\n");
        return NO_WORDS_IN_LINE;
    }
    
    if (y != 0)
        array_of_words[j][y] = '\0';
    else
        j--;
        
    return j + 1;
}

int look_for_repetitions(char array_of_words[][MAXIMUM_WORD_LENGTH + 1],
const int number_of_words, const int word_number)
{
    int same_characters, number_of_meetings, k;
    
    same_characters = 0;
    number_of_meetings = 0;
    k = 0;
    
    for (int i = 0; i < number_of_words; i++)
    {
        for (int j = 0; array_of_words[i][j] != '\0'; j++)
        {
            if (array_of_words[i][j] == array_of_words[word_number][j])
                same_characters++;
            else
                break;
        }
        
        if (array_of_words[i][same_characters] ==
            array_of_words[word_number][same_characters])
        {
            number_of_meetings++;
            
            if (i >= word_number)
                k++;
        }
        
        same_characters = 0;
    }

    if (k != number_of_meetings)
        number_of_meetings = 0;
    
    return number_of_meetings;
}

void result_output(char array_of_words[][MAXIMUM_WORD_LENGTH + 1],
const int number_of_words)
{
    int number_of_meetings;
    
    printf("Result:\n");
    
    for (int i = 0; i < number_of_words; i++)
    {
        number_of_meetings = look_for_repetitions(array_of_words, number_of_words, i);
        
        if (number_of_meetings != 0)
        {
            for (int j = 0; array_of_words[i][j] != '\0'; j++)
                printf("%c", array_of_words[i][j]);
        
            printf(" %d\n", number_of_meetings);
        }
    }
}
