import time
from random import randrange

def main():
    array = [4,6,1,7,2,9,10,3]
    maxElementSize = len(bin(max(array))) - 2

    start_time = time.time()

    newArray = sortArray(array, maxElementSize, 0)

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Execution time: {elapsed_time}")

    print(newArray)


def sortArray(array, maxElementSize, currentCheckedElement):
    newArray = []
    
    if (currentCheckedElement == maxElementSize):
        return array
    
    binArray0 = []
    binArray1 = []

    for element in array:
        if (checkBinaryNumbers(element, maxElementSize, currentCheckedElement) == 1):
            binArray1.append(element)
        else:
            binArray0.append(element)
    
    newArray = newArray + sortArray(binArray0, maxElementSize, currentCheckedElement+1)
    newArray = newArray + sortArray(binArray1, maxElementSize, currentCheckedElement+1)

    return newArray

def checkBinaryNumbers(bin1, maxSize, currentCheckedElement): 
    
    if (format(bin1, f'0{maxSize}b')[currentCheckedElement] == '0'):
        return 0
           
    return 1

main()
