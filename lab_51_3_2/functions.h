#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define OK 0
#define NO_FILE_NAME 1
#define FILE_DOES_NOT_EXIST 2
#define NO_NUMBER_FOUND 3

int find_avg(FILE *f, float *const avg, int *const quantity);
int find_disp(FILE *f, const float avg, float disp, const int quantity);
void checking_three_sigma_rule(FILE *f, const float avg, const float sigm);

#endif
