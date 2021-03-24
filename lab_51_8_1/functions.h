#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define OK 0
#define NO_TWO_HIGHS -1

void write_to_file(FILE *f);
int min(const int distance, const int *const min_distance);
int process(FILE *f, int *const min_distance);

#endif
