#include <stdio.h>
#include <string.h>
#include "functions.h"

void remove_separators_at_the_end(char str[], const char delimiters[])
{
    size_t len_delimiters;
    
    len_delimiters = strlen(delimiters);
    
    for (long int i = strlen(str) - 1; i >= 0; i--)
    {
        for (long int j = 0; j < (long int) len_delimiters; j++)
        {
            if (str[i] == delimiters[j])
                str[i] = '\0';
        }
        
        if (str[i] != '\0')
            break;
    }
}

int fill_an_array_of_words(char str[],
char array_of_words[][MAXIMUM_WORD_LENGTH + 1])
{
    const char delimiters[] = "\n ,;:-.!?";
    char *pword;
    int i = 0;
    size_t world_len;
    
    remove_separators_at_the_end(str, delimiters);
    pword = strtok(str, delimiters);

    while (pword != NULL)
    {
        world_len = strlen(pword);
        
        if (world_len <= MAXIMUM_WORD_LENGTH)
        {
            strncpy(&array_of_words[i][0], pword, MAXIMUM_WORD_LENGTH);
            pword = strtok(NULL, delimiters);
            array_of_words[i][world_len] = '\0';
            i++;
        }
        else
        {
            printf("Превышенно максимальное кол-во букв в слове\n");
            return ERROR_CREATING_WORD;
        }
    }
    
    if (i <= 1)
    {
        printf("Новая строка пустая\n");
        return NEW_LINE_IS_EMPTY;
    }
    
    return i;
}

int are_words_equal(const char word[], const char last_word[])
{
    if (strlen(word) != strlen(last_word))
        return NO;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] != last_word[i])
            return NO;
    }

    return YES;
}

int create_a_new_word(const char word[], char new_word[])
{
    int number_of_characters = 1;
    
    new_word[0] = word[0];
    
    for (int i = 1; word[i] != '\0'; i++)
    {
        if (word[i] != word[0])
        {
            new_word[number_of_characters] = word[i];
            number_of_characters++;
        }
    }
    
    return number_of_characters;
}

void fill_new_str(char new_str[], const int number_of_words,
char array_of_words[][MAXIMUM_WORD_LENGTH + 1])
{
    char new_word[MAXIMUM_WORD_LENGTH];
    int number_of_characters;
    
    new_str[0] = '\0';
    
    for (int i = number_of_words - 2; i >= 0; i--)
    {
        if (are_words_equal(array_of_words[i],
        array_of_words[number_of_words - 1]) == NO)
        {
            number_of_characters = create_a_new_word(array_of_words[i], new_word);
            
            if (i != 0)
            {
                new_word[number_of_characters] = ' ';
                new_word[number_of_characters + 1] = '\0';
            }
            else
            {
                new_word[number_of_characters] = '\0';
            }

            strncat(new_str, new_word, MAX_STR_LEN);
        }
    }
}
