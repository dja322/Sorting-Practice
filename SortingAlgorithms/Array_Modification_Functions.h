#ifndef ARRAY_MODIFICATION_FUNCTIONS
#define ARRAY_MODIFICATION_FUNCTIONS

/*
    UTILITY FUNCTIONS
*/

#include <stdio.h>
#include <stdlib.h>

//copies source array to the destination array
void copyArray(int sourceArray[], int destinationArray[], int sourceArraySize);

//prints out array with each element separated by spaces
//ends with a newline char
void printArray(int Array[], int arraySize);

#endif