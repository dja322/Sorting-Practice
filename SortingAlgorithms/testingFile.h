#ifndef TESTING_FILE
#define TESTING_FILE

#include <stdbool.h>
#include "../munit/munit.h"
#include "Array_Modification_Functions.h"
#include "Bubblesort.h"
#include "InsertBinary.h"
#include "Quicksort.h"
#include "MiddleSort.h"
#include "MeanSort.h"
#include "Mergesort.h"

//checks if an array is sorted in ascending order
bool isSortedLowToHigh(int Array[], int sizeOfArray);

//generates a bit number based on the order of elements in the array
unsigned long long getBitNumber(int Array[], int sizeOfArry);

//initializes an array with random integers
void initializeArray(int Array[], int sizeOfArray);

// Function to test if isSortedLowToHigh works correctly
MunitResult testSorted();

// Function to test if all sorting algorithms work correctly
MunitResult testSortsWork();

// Function to run all tests
int run_Tests(int argc, char* argv[]);


#endif