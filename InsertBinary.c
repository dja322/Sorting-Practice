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

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000

//InsertBinary functions
bool InsertBinary(int Array[], int sizeOfArray);
int moveRight(int Array[], int startIndex, int endIndex);
int binarySearchToFindPosition(int array[], int element, int sortedListEndIndex);

//bubble sort functions
void swap(int* arr, int i, int j);
void bubbleSort(int arr[], int n);

//quicksort functions
void qswap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

//utility functions
void copyArray(int sourceArray[], int destinationArray[], int sourceArraySize);
void printArray(int Array[], int arraySize);

int main()
{
    int testArr[ARRAY_SIZE];
    int testArr2[ARRAY_SIZE];

    //print out unsorted list
    for (int i = 0; i < ARRAY_SIZE; i++) {

        // Find the random number in the range [min, max]
        testArr[i] = rand() % (1000) + 1;

    }
    copyArray(testArr, testArr2, ARRAY_SIZE);
    printf("\n\n");

    //int testArr[] = {42,68,35,1,70,25,79,59,63,65,6,46,82,28,62,92,96,43,28,37};

    /*
        START OF SORTING LOGIC AND TESTING
    */

    struct timeval start, end;
    
    gettimeofday(&start, 0);

    //Start sorting
    quickSort(testArr2, 0, ARRAY_SIZE);

    gettimeofday(&end, 0);
    double timeDif = (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec);
    printf("Time Taken for QuickSort: %lf\n", timeDif);
    /*
            END OF SORTING LOGIC
    */

    gettimeofday(&start, 0);

    //Start sorting
    InsertBinary(testArr, ARRAY_SIZE);

    gettimeofday(&end, 0);

    timeDif = (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec);
    printf("Time Taken for InsertBinary: %lf\n", timeDif);

    return 0;
}

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

/*
    BUBBLE SORT FUNCTIONS
*/

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      
        // Last i elements are already in place, so the loop
        // will only num n - i - 1 times
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}


/*
    QUICKSORT FUNCTIONS
*/

    void qswap(int* a, int* b) 
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

int partition(int arr[], int low, int high) {

    // Initialize pivot to be the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            qswap(&arr[i], &arr[j]);
        }
    }
    qswap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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