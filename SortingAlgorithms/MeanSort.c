/*
    Mean Sort explanation:
    This sorting algorithm is based on the mean of the elements in the array.
    It partitions the array into two parts: elements less than the mean and elements greater than
    or equal to the mean.
    It then recursively sorts each partition until the entire array is sorted.

    Sort steps for this implementations
    1. Calculate the mean of the elements in the current partition.
    2. set the left and right bounds for the sorting of the current partition.
    3. check the left element and if it is less than the mean, increment left.
    4. if the left element is greater than or equal to the mean, swap it
       with the right element and decrement right.
    5. Continue this process until the left and right pointers meet. Then 
       adjust the left and right pointers to ensure they are in the correct position.
       e.g. left should be the last element less than the mean and
       right should be the first element greater than or equal to the mean.
    6. Then recursively call the mean_sort_helper function on the two partitions
       created by the left and right pointers.
    7. Repeat until the entire array is sorted.
    8. The base case for the recursion is when the partition size is less than or equal to 2,
       in which case no further sorting is needed.
*/

#include "MeanSort.h"

//sort function that calls the helper function to sort the array
void mean_sort(int array[], int size)
{
    mean_sort_helper(array, size, 0, size - 1);
}

// Helper function that performs the actual sorting
// It recursively partitions the array based on the mean of the elements
void mean_sort_helper(int array[], int size, int lower_bound, int upper_bound)
{
    // Check if the bounds are valid
    if (lower_bound >= upper_bound)
        return;

    // Calculate the mean of the elements in the current partition
    double mean = 0.0;
    for (int i = lower_bound; i <= upper_bound; i++)
    {
        mean += array[i];
    }
    mean /= (upper_bound - lower_bound + 1);

    //sets the left and right bounds for sorting and partitioning
    int left = lower_bound;
    int right = upper_bound;

    //increment through array until left and right pointers meet
    while (left + 1 <= right)
    {
        // If the left element is less than the mean, increment left
        if (array[left] < mean)
        {
            left++;
        }
        // If the left element is greater than or equal to the mean, swap it with the right element
        // and decrement right
        else if (array[left] >= mean)
        {
            mean_swap(&array[left], &array[right]);
            right--;
        } 
    }
    
    // Check if the partition is too small to sort further
    if (upper_bound - lower_bound < 2)
    {
        return; // No need to sort further if the partition is too small
    }
    else if (upper_bound - lower_bound == 2 && array[left] > array[right])
    {
        mean_swap(&array[left], &array[right]); // Ensure the two elements are in order
        return; // No need to sort further
    }

    // Adjust the left and right pointers to ensure they are in the correct position
    // left should be the last element less than the mean and right should be the first element
    if (array[left] >= mean && left - 1 >= lower_bound)
    {
        left--;
    }
    if (array[right] < mean && right + 1 <= upper_bound)
    {
        right++;
    }

    // Recursively call and sort both partitions if they are valid
    // Prevent infinite recursion by checking bounds
    if (left > lower_bound && left < upper_bound)
        mean_sort_helper(array, size, lower_bound, left);
    if (right > lower_bound && right < upper_bound)
        mean_sort_helper(array, size, right, upper_bound);
}

// Swaps two integers in an array
void mean_swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}