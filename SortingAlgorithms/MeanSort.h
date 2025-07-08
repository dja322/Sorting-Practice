#ifndef MEAN_SORT
#define MEAN_SORT

#include <stdio.h>
#include <stdbool.h>
#include "Array_Modification_Functions.h"

void mean_swap(int* a, int* b);
void mean_sort(int array[], int size);
void mean_sort_helper(int array[], int size, int lower_bound, int upper_bound);


#endif