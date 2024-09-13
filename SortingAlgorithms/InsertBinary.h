#ifndef INSERT_BINARY
#define INSERT_BINARY

#include <stdbool.h>

//sorts list using THE COOL InsertBinary algorithm
bool InsertBinary(int Array[], int sizeOfArray);

/*
    Moves elements in array one to the right, 
    overriding the element to the right and leaving
    a copy of the first element. Returns replaced int
*/
int moveRight(int Array[], int startIndex, int endIndex);


/*
    Using binarySearch to find position of where element should be
*/
int binarySearchToFindPosition(int array[], int element, int sortedListEndIndex);


#endif