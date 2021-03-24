#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_SURNAME_LENGTH 25
#define MAX_NAME_LENGTH 10
#define NUMBER_OF_ITEMS 4
#define YES 1
#define NO 0

#define OK 0
#define INVALID_ARGUMENTS_PASSED 53
#define FILE_DOES_NOT_EXIST 2
#define NO_FILE_SIZE 3
#define COULD_NOT_READ_CHARACTER 4
#define WRONG_FILE_SIZE 5
#define NEW_FILE_IS_EMPTY 6

typedef struct
{
    char surname[MAX_SURNAME_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    unsigned int mark[NUMBER_OF_ITEMS];
} student;

int file_size(FILE *f, size_t *size);
int get_elem_by_pos(FILE *f, const size_t i, student *const student_inf);
void put_elem_by_pos(FILE *f, const size_t i, student *const student_inf);
void print_file(FILE *f);
void sort_file(FILE *f);
int finding_the_right_students(FILE *f, FILE *f_out, const char substr[]);
double average_mark(FILE *f);
void remove_specific_students(FILE *f, size_t size, const char *name_file);

#endif
