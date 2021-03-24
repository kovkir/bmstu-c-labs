#ifndef FINCTIONS_H
#define FINCTIONS_H

#define NUMBER_RANGE 100

#define OK 0
#define INVALID_ARGUMENTS_PASSED 1
#define FILE_DOES_NOT_EXIST 2
#define NO_FILE_SIZE 3
#define COULD_NOT_READ_CHARACTER 4
#define WRONG_FILE_SIZE 5

void create_file(const int quantity, FILE *f);
int file_size(FILE *f);
int get_number_by_pos(FILE *f, const int i, int *const number);
void put_number_by_pos(FILE *f, const int i, int *const number);
int print_file(FILE *f);
int sort_file(FILE *f, const char name_file[]);

#endif
