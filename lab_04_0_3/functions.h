#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_STR_LEN 256
#define MAXIMUM_NUMBER_OF_WORDS MAX_STR_LEN/2 + 1
#define MAXIMUM_WORD_LENGTH 16

#define YES 1
#define NO 0
#define ERROR_ENTERING_STRING -3
#define NEW_LINE_IS_EMPTY -2
#define ERROR_CREATING_WORD -1
#define SUCCESS 0

void remove_separators_at_the_end(char str[], const char delimiters[]);
int fill_an_array_of_words(char str[],
char array_of_words[][MAXIMUM_WORD_LENGTH + 1]);
int are_words_equal(const char word[], const char last_word[]);
int create_a_new_word(const char word[], char new_word[]);
void fill_new_str(char new_str[], const int number_of_words,
char array_of_words[][MAXIMUM_WORD_LENGTH + 1]);

#endif
