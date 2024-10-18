import time
from random import randrange

def main():
    #make array for test
    array = [4,6,1,7,2,9,10,3]

    #find max element of array
    maxElementSize = len(bin(max(array))) - 2

    start_time = time.time()

    #call sort
    newArray = sortArray(array, maxElementSize, 0)

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Execution time: {elapsed_time}")

    print(newArray)

#This uses the binary sort array that seems to be RADIX sort
def sortArray(array, maxElementSize, currentCheckedElement):
    #initialize array to be returned
    newArray = []
    
    #check if lask element is reached
    if (currentCheckedElement == maxElementSize):
        return array
    
    #initialize 2 arrays
    binArray0 = []
    binArray1 = []

    #loops through all current elements and add them to either binArray1 or 0 if char is 1 or 0
    for element in array:
        if (checkBinaryNumbers(element, maxElementSize, currentCheckedElement) == 1):
            binArray1.append(element)
        else:
            binArray0.append(element)
    
    #recurse with new arrays and elements
    newArray = newArray + sortArray(binArray0, maxElementSize, currentCheckedElement+1)
    newArray = newArray + sortArray(binArray1, maxElementSize, currentCheckedElement+1)

    return newArray

#check if a number has the binary of 1 or 0 at the curretn checked index
def checkBinaryNumbers(bin1, maxSize, currentCheckedElement): 
    if (format(bin1, f'0{maxSize}b')[currentCheckedElement] == '0'):
        return 0   
    return 1

main()
