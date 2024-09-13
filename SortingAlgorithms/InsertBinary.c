/*
This is the algorithm for what I am calling the InsertBinary algorithm, 
a method to sort things that may be slow or really quick, and it might
just be quicksort but worse. 

The algorithm works by slowly expanding a subarray of sorted values from the
start of an array to the end. It works like this:

Our test list will be 42,20,35,1,70,25

We have 4 values we need to keep track of, 
The largest value
The smallest value
Starting index of sorted subarray
Ending index of sorted subarray

So we start at index 0 or 42 which starts out subarray
(v is largest, ^ is smallest, * is current index)

v
42,20,35,1,70,25
^

Then we start iterating up, we go up one at a time, sorting that 
element into our sorted list. We will have three choices when 
sorting a new number:

1. If it is larger or equal to our largest element we simply 
continue on and add it to our sorted values
2. If it is smaller or equal to our smallest, we move all 
elements right and place it at the start of our sorted subarray
3. If it is in between the smallest and largest, we iterate through the subarray
to find its correct position, because we have a subarray that is guaranteed to
be sorted, we can leverage binary search(linear also works) to find where the 
element should be placed. Once the spot where it should be has been found, we move
all elements right of where it should be right one index and place the value into
its sorted position

So for example, we have

42,20,35,1,70,25
^
Where 42 is both our largest and smallest, we then start at the second index

v  *
42,20,35,1,70,25
^

since 20 is smaller then our smallest(42), 20, 42 is moved right one spot and 20 is placed
where it was thus we will have
   v  *
20,42,35,1,70,25
^

The sorted subarray is now two long consisting of 20 and 42

The next element is 35 which will trigger our third choice and we will start our binary search.
It will start in the middle of 20 and 42 and since it is already in the right spot it will
place the element there, thus our subarray will look like

      v  *
20,35,42,1,70,25
^

We do the same operations through the whole list until we reach the end of the list where the ending
index of the sorted subarray is at the end of the original array. Now we have an array like
              v
1,20,25,35,42,70
^
*/

#include "InsertBinary.h"

/*
    InsertBinary FUNCTIONS
*/

//sorts list using THE COOL InsertBinary algorithm
bool InsertBinary(int Array[], int sizeOfArray)
{
   int largest = Array[0];
   int middle = 0;
   int smallest = Array[0];
   int sizeOfUnSortedArray = sizeOfArray;
   int sizeOfSortedArray = 1;
   int positionToPlaceElement = -1;

   //runs until sorted list is larger size as unsorted
   while (sizeOfSortedArray <= sizeOfUnSortedArray)
   {

        if (Array[sizeOfSortedArray] >= largest)
        {
            largest = Array[sizeOfSortedArray];
        }
        else if (Array[sizeOfSortedArray] <= smallest)
        {
            smallest = Array[sizeOfSortedArray];
            moveRight(Array,0,sizeOfSortedArray);
            Array[0] = smallest;
        }
        else
        {
            middle = Array[sizeOfSortedArray];

            positionToPlaceElement = 
                binarySearchToFindPosition(Array, 
                Array[sizeOfSortedArray], sizeOfSortedArray);

            moveRight(Array, positionToPlaceElement, sizeOfSortedArray);
            Array[positionToPlaceElement] = middle;

        }
        
        sizeOfSortedArray++;
   }

    return true;
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

