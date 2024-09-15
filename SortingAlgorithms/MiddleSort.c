
#include <stdbool.h>

//sorts list using THE COOL MiddleSort algorithm
bool MiddleSort(int Array[], int sizeOfArray)
{
    
}

/*
    Moves elements in array one to the right, 
    overriding the element to the right and leaving
    a copy of the first element. Returns replaced int
*/
int moveRight(int Array[], int startIndex, int endIndex)
{
    int erasedInteger = Array[endIndex];
    for (int index = endIndex; index >= startIndex; --index)
    {
        Array[index] = Array[index-1];   
    }   
    return erasedInteger;
}


/*
    Using binarySearch to find position of where element should be
*/
int binarySearchToFindPosition(int array[], int element, int sortedListEndIndex)
{
    int low = 0;
    int max = sortedListEndIndex;
    int mid = (max - low) / 2 + low;
    
    //loops through elements until it finds either the same element or
    //it finds the two elements it should be between and returns index of larger one
    while ( !(element >= array[mid-1] && element <= array[mid]) )
    {
        mid = (max - low) / 2 + low;
        if (element > array[mid])
        {
            low = mid + 1;
        }
        else if (element < array[mid])
        {
            max = mid - 1;
        }
        else
        {
            return mid;
        }
        
    }
    return mid;
}

