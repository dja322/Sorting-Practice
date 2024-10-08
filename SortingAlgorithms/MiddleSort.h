#ifndef MIDDLE_SORT
#define MIDDLE_SORT

#include <stdbool.h>

//sorts list using THE COOL InsertBinary algorithm
bool MiddleSort(int Array[], int sizeOfArray);


/*
    Moves elements in array one to the right, 
    overriding the element to the right and leaving
    a copy of the first element. Returns replaced int
*/
int moveRight2(int Array[], int startIndex, int endIndex);

/*
    Moves elements in array one to the left, 
    overriding the element to the left and leaving
    a copy of the first element. Returns replaced int
*/
int moveLeft(int Array[], int startIndex, int endIndex);

/*
    Using binarySearch to find position of where element should be
*/
int binarySearchToFindPosition2(int array[], int element,
        int sortedListStartIndex, int sortedListEndIndex);

#endif