
#include <stdbool.h>

//sorts list using THE COOL MiddleSort algorithm
bool MiddleSort(int Array[], int sizeOfArray)
{
    int startIndex = 0;
    int midStartIndex = sizeOfArray / 2;
    int endIndex = sizeOfArray-1;
    int currentMidArraySizes = (sizeOfArray % 2 == 0) ? 1 : 0;
    int fourOrderArray[4];

    find_order(Array[startIndex], Array[midStartIndex], 
    Array[midStartIndex + currentMidArraySizes], Array[endIndex], 
    &fourOrderArray[0], &fourOrderArray[1],
    &fourOrderArray[2], &fourOrderArray[3]);

}

void find_order(int a, int b, int c, int d, int *lowest, int *middle1, int *middle2, int *highest) {
    int low1, high1, low2, high2;

    if (a < b) {
        low1 = a;
        high1 = b;
    } else {
        low1 = b;
        high1 = a;
    }

    if (c < d) {
        low2 = c;
        high2 = d;
    } else {
        low2 = d;
        high2 = c;
    }

    if (low1 < low2) {
        *lowest = low1;
        *middle1 = low2;
    } else {
        *lowest = low2;
        *middle1 = low1;
    }

    if (high1 > high2) {
        *highest = high1;
        *middle2 = high2;
    } else {
        *highest = high2;
        *middle2 = high1;
    }

    if (!(*middle1 < *middle2)) {
        // Swap middle1 and middle2
        int temp = *middle1;
        *middle1 = *middle2;
        *middle2 = temp;
    }
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

