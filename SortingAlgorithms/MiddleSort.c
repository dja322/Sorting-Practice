
#include <stdbool.h>
#include "MiddleSort.h"
#include "Array_Modification_Functions.h"

//sorts list using THE COOL MiddleSort algorithm
bool MiddleSort(int Array[], int sizeOfArray)
{
    int startIndex = sizeOfArray/2 - 1;
    int currentSortedSize = sizeOfArray % 2 == 0 ? 1 : 0;
    int endIndex = startIndex + currentSortedSize;
    int replacePosition;
    int currentLarge;
    int currentLow;

    printf("%d %d\n", startIndex, endIndex);

    printArray(Array, sizeOfArray);


    if (Array[startIndex] > Array[endIndex])
    {
        currentLarge = Array[startIndex];
        currentLow = Array[endIndex];
    }
    else
    {
        currentLow = Array[startIndex];
        currentLarge = Array[endIndex];
    }

    Array[startIndex] = currentLow;
    Array[endIndex] = currentLarge;

    printf("%d %d\n", startIndex, endIndex);
    printf("%d %d\n", currentLow, currentLarge);
    printArray(Array, sizeOfArray);

    startIndex--;
    endIndex++;

    while (startIndex >= 0 && endIndex < sizeOfArray)
    {
        

        if (Array[startIndex] > Array[endIndex])
        {
            currentLarge = Array[startIndex];
            currentLow = Array[endIndex];
        }
        else
        {
            currentLow = Array[startIndex];
            currentLarge = Array[endIndex];
        }

        if (currentLow < Array[startIndex+1])
        {
            Array[startIndex] = currentLow;

            if (currentLarge < Array[endIndex-1])
            {
                replacePosition = binarySearchToFindPosition2(Array, currentLarge,
                                  startIndex, endIndex-1);
                moveRight2(Array, replacePosition, endIndex);
                Array[replacePosition] = currentLarge;
            }
            printf("S1: ");

        }
        else if (currentLow > Array[endIndex-1])
        {
            moveLeft(Array, startIndex, endIndex-1);
            Array[endIndex-1] = currentLow;
            Array[endIndex] = currentLarge;
            printf("S2: ");
            
        }
        else
        {

            /*
                Currently broken
            */
            replacePosition = binarySearchToFindPosition2(Array, currentLow,
                              startIndex+1, endIndex-1);
            moveLeft(Array, startIndex, replacePosition-1);
            Array[replacePosition-1] = currentLow;

            replacePosition = binarySearchToFindPosition2(Array, currentLarge,
                              startIndex, endIndex-1);
            moveRight2(Array, replacePosition, endIndex);
            Array[replacePosition] = currentLarge;


            printf("S3: ");
            
        }

        printf("%d %d\n", startIndex, endIndex);
        printf("%d %d\n", currentLow, currentLarge);
        printArray(Array, sizeOfArray);

        startIndex--;
        endIndex++;
    }

    printArray(Array, sizeOfArray);


    return true;

}

//puts 4 elements into 4 output variables in order
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
int moveRight2(int Array[], int startIndex, int endIndex)
{
    int erasedInteger = Array[endIndex];
    for (int index = endIndex; index >= startIndex; --index)
    {
        Array[index] = Array[index-1];   
    }   
    return erasedInteger;
}

/*
    Moves elements in array one to the left, 
    overriding the element to the left and leaving
    a copy of the first element. Returns replaced int
*/
int moveLeft(int Array[], int startIndex, int endIndex)
{
    int erasedInteger = Array[endIndex];
    for (int index = startIndex; index <= endIndex; ++index)
    {
        Array[index] = Array[index+1];   
    }   
    return erasedInteger;
}


/*
    Using binarySearch to find position of where element should be
*/
int binarySearchToFindPosition2(int array[], int element,
        int sortedListStartIndex, int sortedListEndIndex)
{
    int low = sortedListStartIndex;
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

