
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
#include "MeanSort.h"
#include "Mergesort.h"
#include "testingFile.h"

//Variable definitions for testing and analysis
//Define the size of the arrays, number of arrays, and number of sorts 
//that are being tested and analyzed
//These can be changed to test different sizes and numbers of sorts
//If NUMBER_OF_SORTS is changed, the analyze function will need to be updated
//to account for the new number of sorts
#define ARRAY_SIZE 10000
#define NUMBER_OF_ARRAYS 10
#define NUMBER_OF_SORTS 6

//function prototypes
void analyze(
    //create 3D array for sorts and a group of array of size ARRAY_SIZE
    int Array[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS][ARRAY_SIZE],
    //bit number array for analysis
    unsigned long long sortednessArray[NUMBER_OF_ARRAYS],
    //stores the time needed to sort each array
    long timesArray[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS]
);

int main(int argc, char* argv[])
{
    run_Tests(argc, argv);
    puts("\nTests Concluded, beginning analysis:\n");

    //create 3D array for sorts and a group of array of size ARRAY_SIZE
    int Array[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS][ARRAY_SIZE];
    //bit number array for analysis
    unsigned long long sortednessArray[ARRAY_SIZE];
    //stores the time needed to sort each array
    long timesArray[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS];

    //initialize the arrays and copy them to each of the sorting methods
    //This is done so that each sorting method has the same initial array to sort
    for (int arrNumber = 0; arrNumber < NUMBER_OF_ARRAYS; ++arrNumber)
    {
        initializeArray(Array[0][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[1][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[2][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[3][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[4][arrNumber], ARRAY_SIZE);
        copyArray(Array[0][arrNumber], Array[5][arrNumber], ARRAY_SIZE);

        sortednessArray[arrNumber] = getSortednessNumber(Array[0][arrNumber], ARRAY_SIZE);
    }
    
    //create a timeval struct to measure the time taken by each sorting method
    struct timeval start, end;
    
    //loop through every array and sort them using each of the sorting methods
    //and measure the time taken by each sorting method
    for (int arrNumber = 0; arrNumber < NUMBER_OF_ARRAYS; ++arrNumber)
    {
        //middle sort measure

        gettimeofday(&start, 0);

        MiddleSort(Array[0][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[0][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

        //InsertBinary sort measure

        gettimeofday(&start, 0);

        InsertBinary(Array[1][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[1][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

        //QuickSort

        gettimeofday(&start, 0);

        quickSort(Array[2][arrNumber], 0, ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[2][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

        gettimeofday(&start, 0);

        bubbleSort(Array[3][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[3][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

        //MeanSort
        gettimeofday(&start, 0);

        mean_sort(Array[4][arrNumber], ARRAY_SIZE);

        gettimeofday(&end, 0);

        timesArray[4][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

        //Mergesort
        gettimeofday(&start, 0);

        mergeSort(Array[5][arrNumber], 0, ARRAY_SIZE - 1);

        gettimeofday(&end, 0);

        timesArray[5][arrNumber] = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
    }

    //print the results of the sorting methods and their times
    for (int index = 0; index < NUMBER_OF_ARRAYS; ++index)
    {
        printf("Order Binary Number: %llu\n", sortednessArray[index]);
        printf("MiddleSort: %ld\n", timesArray[0][index]);
        printf("InsertBinarySort: %ld\n", timesArray[1][index]);
        printf("QuickSort: %ld\n", timesArray[2][index]);
        printf("BubblesSort: %ld\n", timesArray[3][index]);
        printf("MeanSort: %ld\n", timesArray[4][index]);
        printf("Mergesort: %ld\n", timesArray[5][index]);

        printf("\n\n");

    }

    analyze(Array, sortednessArray, timesArray);

    return 0;
}

//generic analyzing, will specify further
void analyze(
    //create 3D array for sorts and a group of array of size ARRAY_SIZE
    int Array[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS][ARRAY_SIZE],
    //bit number array for analysis
    unsigned long long sortednessArray[NUMBER_OF_ARRAYS],
    //stores the time needed to sort each array
    long timesArray[NUMBER_OF_SORTS][NUMBER_OF_ARRAYS]
)
{
    /*
        What to find out
        What kind of list is each sort most effecient for
        How does the difference in bin numbers impact performance of each sort
    */
    printf("Below is a table and analysis of the sorting methods\n");

    unsigned long long averageBinary = 0;
    int* averageTimes = malloc(sizeof(int) * NUMBER_OF_ARRAYS);
    for (int i = 0; i < NUMBER_OF_ARRAYS; i++)
    {
        averageTimes[i] = 0;
    }


    //find averages of binary and sort times
    for (int index = 0; index < NUMBER_OF_ARRAYS; index++)
    {
        //add to average binary and times
        averageBinary = averageBinary + sortednessArray[index] / NUMBER_OF_ARRAYS;
        averageTimes[0] += timesArray[0][index];
        averageTimes[1] += timesArray[1][index];
        averageTimes[2] += timesArray[2][index];
        averageTimes[3] += timesArray[3][index];
        averageTimes[4] += timesArray[4][index];
        averageTimes[5] += timesArray[5][index];
    }
    //divide by number of arrays to get average
    averageTimes[0] /= NUMBER_OF_ARRAYS;
    averageTimes[1] /= NUMBER_OF_ARRAYS;
    averageTimes[2] /= NUMBER_OF_ARRAYS;
    averageTimes[3] /= NUMBER_OF_ARRAYS;
    averageTimes[4] /= NUMBER_OF_ARRAYS;
    averageTimes[5] /= NUMBER_OF_ARRAYS;

    //print the averages
    printf("Average binary number: %llu\n", averageBinary);
    printf("Average time for MiddleSort: %d\n", averageTimes[0]);
    printf("Average time for InsertBinarySort: %d\n", averageTimes[1]);
    printf("Average time for QuickSort: %d\n", averageTimes[2]);
    printf("Average time for BubblesSort: %d\n", averageTimes[3]);
    printf("Average time for MeanSort: %d\n", averageTimes[4]);
    printf("Average time for Mergesort: %d\n", averageTimes[5]);

    free(averageTimes);
}
