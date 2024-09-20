
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
#define NUMBER_OF_ARRAYS 10
#define NUMBER_OF_SORTS 4

int main(int argc, char* argv[])
{
    run_Tests(argc, argv);
    puts("\nTests Conculded, beginning analysis:\n");

    int Array[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS][ARRAY_SIZE];
    unsigned long long bitNumberArray[ARRAY_SIZE];

    for (int arrNumber = 0; arrNumber < NUMBER_OF_ARRAYS; ++arrNumber)
    {
        initializeArray(Array[0][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[1][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[2][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[3][arrNumber], ARRAY_SIZE);

        bitNumberArray[arrNumber] = getBitNumber(Array[0][arrNumber], ARRAY_SIZE);
    }
        


    struct timeval start, end;
    
    gettimeofday(&start, 0);

    gettimeofday(&end, 0);

    double timeDif = (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec);
    printf("Time Taken for Middlesort: %lf\n", timeDif);


    return 0;
}




