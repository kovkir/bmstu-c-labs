#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"

int file_size(FILE *f, size_t *size)
{
    size_t sz;
    
    if (fseek(f, 0L, SEEK_END))
    {
        return NO_FILE_SIZE;
    }
    
    sz = ftell(f);
    *size = sz;
    
    if (sz <= 0)
    {
        return NO_FILE_SIZE;
    }
    else if (sz % 4 != 0)
    {
        return WRONG_FILE_SIZE;
    }
    
    return fseek(f, 0L, SEEK_SET);
}

int get_elem_by_pos(FILE *f, const size_t i, student *const student_inf) 
{
    size_t kol;
    
    fseek(f, i * sizeof(student), SEEK_SET);
    kol = fread(student_inf, sizeof(student), 1, f);
    
    if (kol != 1)
    {
        return COULD_NOT_READ_CHARACTER;
    }

    return OK;
}

void put_elem_by_pos(FILE *f, const size_t i, student *const student_inf)
{
    fseek(f, i * sizeof(student), SEEK_SET);
    fwrite(student_inf, sizeof(student), 1, f);
}

void print_file(FILE *f)
{
    student student_inf;

    for (size_t i = 0; get_elem_by_pos(f, i, &student_inf) == OK; i++)
    {
        printf("%s %s [%u, %u, %u, %u]\n",
        student_inf.surname, student_inf.name,
        student_inf.mark[0], student_inf.mark[1],
        student_inf.mark[2], student_inf.mark[3]);
    }
}

void sort_file(FILE *f)
{
    student student_inf, min, a, b;
    size_t j_min, quantity = 0;
    
    for (size_t i = 0; get_elem_by_pos(f, i, &student_inf) == OK; i++)
    {
        min = student_inf;
        j_min = i;
        
        for (size_t j = i; get_elem_by_pos(f, j, &student_inf) == OK; j++)
        {
            if (strcmp(student_inf.surname, min.surname) < 0)
            {
                quantity++;
                j_min = j;
                get_elem_by_pos(f, j, &min);
            }
            else if (strcmp(student_inf.surname, min.surname) == 0 &&
                strcmp(student_inf.name, min.name) < 0)
            {
                quantity++;
                j_min = j;
                get_elem_by_pos(f, j, &min);
            }
        }

        get_elem_by_pos(f, i, &a);
        get_elem_by_pos(f, j_min, &b);
        put_elem_by_pos(f, j_min, &a);
        put_elem_by_pos(f, i, &b);
    }
}

int finding_the_right_students(FILE *f, FILE *f_out, const char substr[])
{
    student student_inf;
    int quantity = 0;
    
    size_t len_surname;
    size_t len_substr;
    
    for (size_t i = 0; get_elem_by_pos(f, i, &student_inf) == OK; i++)
    {
        len_surname = strlen(student_inf.surname);
        len_substr = strlen(substr);
        
        if (len_surname >= len_substr &&
            strncmp(student_inf.surname, substr, len_substr) == 0)
        {
            quantity++;
            fwrite(&student_inf, sizeof(student), 1, f_out);
        }
    }
    
    if (quantity == 0)
    {
        return NEW_FILE_IS_EMPTY;
    }
    else
    {
        return OK;
    }
}

double average_mark(FILE *f)
{
    student student_inf;
    double aver_mark, sum = 0;
    size_t quantity = 0;
    
    for (size_t i = 0; get_elem_by_pos(f, i, &student_inf) == OK; i++)
    {
        sum += (double) (student_inf.mark[0] + student_inf.mark[1] +
            student_inf.mark[2] + student_inf.mark[3]) / 4;
        quantity++;
    }
    
    aver_mark = sum / quantity;
    
    return aver_mark;
}

void remove_specific_students(FILE *f, size_t size, const char *name_file)
{
    student student_inf, a, b;
    double aver_mark, student_grade;
    
    aver_mark = average_mark(f);

    for (size_t i = 0; get_elem_by_pos(f, i, &student_inf) == OK; i++)
    {
        student_grade = (double) (student_inf.mark[0] + student_inf.mark[1] +
            student_inf.mark[2] + student_inf.mark[3]) / 4;
        
        if (student_grade < aver_mark)
        {
            for (size_t j = i + 1; get_elem_by_pos(f, j, &student_inf) == OK; j++)
            {
                get_elem_by_pos(f, j, &a);
                get_elem_by_pos(f, j - 1, &b);
                put_elem_by_pos(f, j - 1, &a);
                put_elem_by_pos(f, j, &b);
            }
            
            i--;
            size -= sizeof(student);
            truncate(name_file, size);
        }
    }
}

