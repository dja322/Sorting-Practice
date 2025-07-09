/*
    Mean sort functions
*/

#include "MeanSort.h"

void mean_sort(int array[], int size)
{
    mean_sort_helper(array, size, 0, size - 1);
}

void mean_sort_helper(int array[], int size, int lower_bound, int upper_bound)
{
    if (lower_bound >= upper_bound)
        return;
    //check if array is sorted
    // if (mean_isSortedLowToHigh(array, size))
    //     return;

    double mean = 0.0;
    for (int i = lower_bound; i <= upper_bound; i++)
    {
        mean += array[i];
    }
    mean /= (upper_bound - lower_bound + 1);

    int left = lower_bound;
    int right = upper_bound;


    while (left + 1 <= right)
    {
        if (array[left] < mean)
        {
            left++;
        }
        else if (array[left] >= mean)
        {
            mean_swap(&array[left], &array[right]);
            right--;
        } 
    }
    if (array[left] >= mean)
    {
        left--;
    }
    if (array[right] < mean)
    {
        right++;
    }

    if (upper_bound - lower_bound < 2)
    {
        return; // No need to sort further if the partition is too small
    }
    else if (upper_bound - lower_bound == 2 && array[left] > array[right])
    {
        mean_swap(&array[left], &array[right]); // Ensure the two elements are in order
        return; // No need to sort further
    }

    // Recursively sort both partitions
    if (left > lower_bound && left < upper_bound)
        mean_sort_helper(array, size, lower_bound, left);
    if (right > lower_bound && right < upper_bound)
        mean_sort_helper(array, size, right, upper_bound);
}

void mean_swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}