#ifndef TESTING_FILE
#define TESTING_FILE

#include <stdbool.h>
#include "../munit/munit.h"
#include "Array_Modification_Functions.h"
#include "Bubblesort.h"
#include "InsertBinary.h"
#include "Quicksort.h"
#include "MiddleSort.h"

#define ARRAY_SIZE 10

bool isSortedLowToHigh(int Array[], int sizeOfArray);

unsigned long long getBitNumber(int Array[], int sizeOfArry);

MunitResult testSorted();

MunitResult testSortsWork();

int run_Tests(int argc, char* argv[]);


#endif