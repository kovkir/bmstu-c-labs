#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_STR_LEN 256
#define MAXIMUM_NUMBER_OF_WORDS MAX_STR_LEN/2 + 1
#define MAXIMUM_WORD_LENGTH 16

#define YES 1
#define NO 0
#define EMPTY_LINE -1
#define LINE_INPUT_ERROR -2
#define MISTAKE_FILLING_OUT_THE_WORD -3
#define NO_WORDS_IN_LINE -4
#define SUCCESS 0

int line_input(char str[], const int line_length);
int punctuation_or_space(char *symbol);
int fill_an_array_of_words(char str[],
char array_of_words[][MAXIMUM_WORD_LENGTH + 1]);
int look_for_repetitions(char array_of_words[][MAXIMUM_WORD_LENGTH + 1],
const int number_of_words, const int word_number);
void result_output(char array_of_words[][MAXIMUM_WORD_LENGTH + 1],
const int number_of_words);

#endif
