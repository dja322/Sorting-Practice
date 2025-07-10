
#include "testingFile.h"

#define ARRAY_SIZE 10

// Function to find the bit number of an array
// This function calculates a bit number based on the order of elements in the array.
// It iterates through the array and checks if each element is greater than the next one.
// the more unsorted the array is, the higher the bit number will be
// Better ways to calculate the Unsortedness of an array could be implemented eventually
unsigned long long getBitNumber(int Array[], int sizeOfArry)
{
    unsigned long long bitNumber = 0;

    for (int index = 0; index < sizeOfArry - 1; index++)
    {
        if (Array[index] > Array[index+1])
        {
            bitNumber = bitNumber + (1 << index);
        }
    }

    return bitNumber;
}

//function to check if an array is sorted in ascending order
bool isSortedLowToHigh(int Array[], int sizeOfArray)
{
    for (int index = 1; index < sizeOfArray; ++index)
    {
        if (Array[index] < Array[index-1])
        {
            return false;
        }
    }
    return true;
}

// Function to initialize an array with random integers
void initializeArray(int Array[], int sizeOfArray)
{
    int rand = munit_rand_int_range(1, 100);

    for (int index = 0; index < sizeOfArray; ++index)
    {
        Array[index] = rand;
        rand = munit_rand_int_range(1, 10);
    }
}

// Create tests using Munit framework to test basic sorting functionality
MunitResult testSorted()
{
    int testArr1[] = {1,2,3,4};
    int testArr2[] = {0,0,3,4,6,7,7,7,9};
    int testArr3[] = {1,2,3,4,3,5,6};

    munit_assert(isSortedLowToHigh(testArr1, 4));

    munit_assert(isSortedLowToHigh(testArr2, 9));

    munit_assert(!isSortedLowToHigh(testArr3, 7));

    return MUNIT_OK;

}

// Function to test if all sorting algorithms work correctly
// This function initializes several arrays with random integers, sorts them using different algorithms,
// and then checks if the sorted arrays are in ascending order.
MunitResult testSortsWork()
{
    //declare arrays
    int middleSortTestArr[ARRAY_SIZE]; 
    int quickSortTestArr[ARRAY_SIZE];
    int binInsertSortTestArr[ARRAY_SIZE];
    int bubbleSortTestArr[ARRAY_SIZE];
    int meanSortTestArr[ARRAY_SIZE];

    //initialize arrays with random integers
    int rand;
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        rand = munit_rand_int_range(1, 10);
        middleSortTestArr[index] = rand;
        quickSortTestArr[index] = rand;
        binInsertSortTestArr[index] = rand;
        bubbleSortTestArr[index] = rand;
        meanSortTestArr[index] = rand;
    }
    
    //sort arrays using different algorithms
    MiddleSort(middleSortTestArr, ARRAY_SIZE);
    quickSort(quickSortTestArr, 0, ARRAY_SIZE);
    InsertBinary(binInsertSortTestArr, ARRAY_SIZE);
    bubbleSort(bubbleSortTestArr, ARRAY_SIZE);
    mean_sort(meanSortTestArr, ARRAY_SIZE);

    //check if arrays are sorted in ascending order
    // If the arrays are sorted correctly, the function will return MUNIT_OK.
    // If any of the arrays are not sorted, the function will fail.
    munit_assert(isSortedLowToHigh(middleSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(quickSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(binInsertSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(bubbleSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(meanSortTestArr, ARRAY_SIZE));

    return MUNIT_OK;
}

// Define the tests to be run by the Munit framework
MunitTest tests[] = {
  { "/testSorted", testSorted, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/my-testSortsWork", testSortsWork, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL}
};

// Define the test suite that includes the tests
static const MunitSuite test_suite = {
  (char*) "", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Function to run the tests using the Munit framework
int run_Tests(int argc, char* argv[])
{
    return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}