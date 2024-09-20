
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <time.h>

// #include <munit/munit.h>

#include "Array_Modification_Functions.h"
#include "Bubblesort.h"
#include "InsertBinary.h"
#include "Quicksort.h"
#include "MiddleSort.h"
#include "testingFile.h"


#define ARRAY_SIZE 10

int main(int argc, char* argv[])
{
    int testArr[ARRAY_SIZE];

    srand(time(NULL));

    // print out unsorted list
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        // Find the random number in the range [min, max]
        testArr[i] = rand() % (100) + 1;

    }
    // copyArray(testArr, testArr2, ARRAY_SIZE);
    printf("\n\n");

    struct timeval start, end;
    
    gettimeofday(&start, 0);

    //Start sorting
    MiddleSort(testArr, ARRAY_SIZE);

    gettimeofday(&end, 0);

    double timeDif = (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec);
    printf("Time Taken for Middlesort: %lf\n", timeDif);


    unsigned long long num = 0;
    int tArr[] = {1,2,4,3,2};

    num = getBitNumber(tArr, 5);

    printf("\n %llu", num);
    
    run_Tests(argc, argv);
    return 0;
}




