#ifndef MEAN_SORT
#define MEAN_SORT

#include <stdio.h>
#include <stdbool.h>
#include "Array_Modification_Functions.h"

/*
    Swaps two integers in an array
    duplicate of other functions in other files
*/
void mean_swap(int* a, int* b);

/*
    Mean sort function that simply calls the helper function
*/
void mean_sort(int array[], int size);

/*
    Mean sort helper function that performs the actual sorting
*/
void mean_sort_helper(int array[], int size, int lower_bound, int upper_bound);


#endif