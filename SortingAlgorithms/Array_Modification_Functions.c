
#include "Array_Modification_Functions.h"

/*
    UTILITY FUNCTIONS
*/

//copies source array to the destination array
void copyArray(int sourceArray[], int destinationArray[], int sourceArraySize)
{
    for (int i = 0; i < sourceArraySize; ++i)
    {
        destinationArray[i] = sourceArray[i];
    }
}

//prints out array with each element separated by spaces
//ends with a newline char
void printArray(int Array[], int arraySize)
{
    for (int index = 0; index < arraySize; ++index)
    {
        printf("%d ", Array[index]);
    }
    printf("\n");
}