
#include <stdbool.h>
#include <stdio.h>
#include "MiddleSort.h"
#include "Array_Modification_Functions.h"

//sorts list using THE COOL MiddleSort algorithm
bool MiddleSort(int Array[], int sizeOfArray)
{
    int currentSortedSize = sizeOfArray % 2 == 0 ? 1 : 0;
    int startIndex = sizeOfArray/2 - currentSortedSize;
    int endIndex = startIndex + currentSortedSize;
    int replacePosition;
    int currentLarge;
    int currentLow;

    //create initial state with sorted one or two elements
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

    //set array preloop state
    Array[startIndex] = currentLow;
    Array[endIndex] = currentLarge;

    startIndex -= 1;
    endIndex += 1;

    //loop until end of array is passed
    while (startIndex >= 0 && endIndex < sizeOfArray)
    {
        //checks which of the two picks is larger/smaller
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

        //if block to determine how elements are moved around and places
            //if low is lowest
        if (currentLow < Array[startIndex+1])
        {
            Array[startIndex] = currentLow;

            //check where largeest should go
            if (currentLarge < Array[endIndex-1])
            {
                replacePosition = binarySearchToFindPosition2(Array, currentLarge,
                                  startIndex, endIndex-1);
                moveRight2(Array, replacePosition, endIndex);
                Array[replacePosition] = currentLarge;
            }
            else
            {
                Array[endIndex] = currentLarge;
            }
        }
        //if the lowest and larger are the biggest so far
        else if (currentLow > Array[endIndex-1])
        {
            moveLeft(Array, startIndex, endIndex-1);
            Array[endIndex-1] = currentLow;
            Array[endIndex] = currentLarge;
        }
        //if low tested value is not the largest or smallest
        else
        {
            replacePosition = binarySearchToFindPosition2(Array, currentLow,
                              startIndex+1, endIndex-1);
            moveLeft(Array, startIndex, replacePosition-1);
            Array[replacePosition-1] = currentLow;

            //check where largest should go, either at end or in sorted list
            if (currentLarge < Array[endIndex-1])
            {
                replacePosition = binarySearchToFindPosition2(Array, currentLarge,
                                startIndex, endIndex-1);
                moveRight2(Array, replacePosition, endIndex);
                Array[replacePosition] = currentLarge; 
            }
            else
            {
                Array[endIndex] = currentLarge;
            }
        }
        
        //increment sorted array
        startIndex--;
        endIndex++;
    }
    return true;
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

