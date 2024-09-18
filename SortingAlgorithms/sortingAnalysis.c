
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

#define ARRAY_SIZE 8


int main()
{
    int testArr[ARRAY_SIZE];
    int testArr2[ARRAY_SIZE];

    srand(time(NULL));

    //print out unsorted list
    for (int i = 0; i < ARRAY_SIZE; i++) {

        // Find the random number in the range [min, max]
        testArr[i] = rand() % (1000) + 1;

    }
    copyArray(testArr, testArr2, ARRAY_SIZE);
    printf("\n\n");

    //int testArr[] = {42,68,35,1,70,25,79,59,63,65,6,46,82,28,62,92,96,43,28,37};

    /*
        START OF SORTING LOGIC AND TESTING
    */

    struct timeval start, end;
    
    gettimeofday(&start, 0);

    //Start sorting
    quickSort(testArr2, 0, ARRAY_SIZE);

    gettimeofday(&end, 0);
    double timeDif = (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec);
    printf("Time Taken for QuickSort: %lf\n", timeDif);
    /*
            END OF SORTING LOGIC
    */

    

    gettimeofday(&start, 0);

    //Start sorting
    MiddleSort(testArr, ARRAY_SIZE);

    gettimeofday(&end, 0);

    timeDif = (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec);
    printf("Time Taken for Middlesort: %lf\n", timeDif);

    
    return 0;
}
