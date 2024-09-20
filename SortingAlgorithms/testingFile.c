
#include "testingFile.h"

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

MunitResult testSortsWork()
{
    int middleSortTestArr[ARRAY_SIZE]; 
    int quickSortTestArr[ARRAY_SIZE];
    int binInsertSortTestArr[ARRAY_SIZE];
    int bubbleSortTestArr[ARRAY_SIZE];

    int rand;
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        rand = munit_rand_int_range(1, 10);
        middleSortTestArr[index] = rand;
        quickSortTestArr[index] = rand;
        binInsertSortTestArr[index] = rand;
        bubbleSortTestArr[index] = rand;
    }


    MiddleSort(middleSortTestArr, ARRAY_SIZE);
    quickSort(quickSortTestArr, 0, ARRAY_SIZE);
    InsertBinary(binInsertSortTestArr, ARRAY_SIZE);
    bubbleSort(bubbleSortTestArr, ARRAY_SIZE);

    munit_assert(isSortedLowToHigh(middleSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(quickSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(binInsertSortTestArr, ARRAY_SIZE));
    munit_assert(isSortedLowToHigh(bubbleSortTestArr, ARRAY_SIZE));

    return MUNIT_OK;
}

MunitTest tests[] = {
  { "/testSorted", testSorted, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/my-testSortsWork", testSortsWork, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL}
};

static const MunitSuite test_suite = {
  (char*) "", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};



int run_Tests(int argc, char* argv[])
{
    return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
    // testSorted();
    // testSortsWork();
}