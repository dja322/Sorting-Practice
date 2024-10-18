
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


#define ARRAY_SIZE 100
#define NUMBER_OF_ARRAYS 10
#define NUMBER_OF_SORTS 4

int main(int argc, char* argv[])
{
    run_Tests(argc, argv);
    puts("\nTests Conculded, beginning analysis:\n");

    int Array[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS][ARRAY_SIZE];
    unsigned long long bitNumberArray[ARRAY_SIZE];
    long timesArray[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS];

    for (int arrNumber = 0; arrNumber < NUMBER_OF_ARRAYS; ++arrNumber)
    {
        initializeArray(Array[0][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[1][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[2][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[3][arrNumber], ARRAY_SIZE);

        bitNumberArray[arrNumber] = getBitNumber(Array[0][arrNumber], ARRAY_SIZE);
    }
        
    
    struct timeval start, end;
    
    for (int arrNumber = 0; arrNumber < NUMBER_OF_ARRAYS; ++arrNumber)
    {
        //middle sort measure

        gettimeofday(&start, 0);

        MiddleSort(Array[0][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[0][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;//(end.tv_sec - start.tv_sec);// + 1e-10 * (end.tv_usec - start.tv_usec);

        //InsertBinary sort measure

        gettimeofday(&start, 0);

        InsertBinary(Array[1][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[1][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;//(end.tv_sec - start.tv_sec);// + 1e-10 * (end.tv_usec - start.tv_usec);

        //QuickSort

        gettimeofday(&start, 0);

        quickSort(Array[2][arrNumber], 0, ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[2][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;//(end.tv_sec - start.tv_sec);// + 1e-10 * (end.tv_usec - start.tv_usec);

        gettimeofday(&start, 0);

        bubbleSort(Array[3][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[3][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;//(end.tv_sec - start.tv_sec);// + 1e-10 * (end.tv_usec - start.tv_usec);
    }


    for (int index = 0; index < NUMBER_OF_ARRAYS; ++index)
    {
        printf("Order Binary Number: %llu\n", bitNumberArray[index]);
        printf("MiddleSort: %ld\n", timesArray[0][index]);
        printf("InsertBinarySort: %ld\n", timesArray[1][index]);
        printf("QuickSort: %ld\n", timesArray[2][index]);
        printf("BubblesSort: %ld\n", timesArray[3][index]);
        printf("\n\n");
    }


    return 0;
}




