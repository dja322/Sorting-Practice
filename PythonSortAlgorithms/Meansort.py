import random
import time

def mean_sort(array):
    mean_sort_helper(array, 0, len(array) - 1)

def mean_sort_helper(array, lower_bound, upper_bound):
    size = upper_bound - lower_bound + 1

    if lower_bound >= upper_bound:
        return

    mean = sum(array[lower_bound:upper_bound + 1]) / size

    left, right = lower_bound, upper_bound
    while left + 1 <= right:
        # If the left element is less than the mean, increment left
        if (array[left] < mean):
            left += 1
        
        # If the left element is greater than or equal to the mean, swap it with the right element
        # and decrement right
        elif (array[left] >= mean):
            mean_swap(array, left, right)
            right -= 1

    if (array[left] >= mean and left - 1 >= lower_bound):
        left -= 1
    
    if (array[right] < mean and right + 1 <= upper_bound):
        right += 1

    # Prevent infinite recursion by checking partition progress
    if left > lower_bound and left < upper_bound:
        mean_sort_helper(array, lower_bound, left)
    if right > lower_bound and right < upper_bound:
        mean_sort_helper(array, right, upper_bound)

def mean_swap(array, i, j):
    array[i], array[j] = array[j], array[i]

def generate_random_array(size, lower=0, upper=100):
    """Generate a random array of integers of given size and range."""
    return [random.randint(lower, upper) for _ in range(size)]

def is_sorted(array):
    """Return True if the array is sorted in non-decreasing order."""
    return all(array[i] <= array[i + 1] for i in range(len(array) - 1))

def main():
    # Example usage
    array = generate_random_array(100, 0, 100)
    array_copy = array.copy()
    array_copy_2 = array.copy()
    print("Original array:", array)

    start_time = time.perf_counter_ns()
    mean_sort(array)
    end_time = time.perf_counter_ns()
    elapsed_time = end_time - start_time

    print(f"Execution time for mean sort : {elapsed_time:.6f} seconds")

    start_time = time.perf_counter_ns()
    quicksort(array_copy)  # Using Python's built-in sort for comparison
    end_time = time.perf_counter_ns()
    elapsed_time_builtin = end_time - start_time
    print(f"Execution time for quick sort: {elapsed_time_builtin:.6f} seconds")

    start_time = time.perf_counter_ns()
    mergesort(array_copy_2)  # Using Python's built-in sort for comparison
    end_time = time.perf_counter_ns()
    elapsed_time_builtin = end_time - start_time
    print(f"Execution time for merge sort: {elapsed_time_builtin:.6f} seconds")
    
    if is_sorted(array):
        print("Mean sort successfully sorted the array.")

    print("Sorted array:", array)

# Quicksort implementation
def quicksort(array):
    def _quicksort(arr, low, high):
        if low < high:
            pi = partition(arr, low, high)
            _quicksort(arr, low, pi - 1)
            _quicksort(arr, pi + 1, high)

    def partition(arr, low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    _quicksort(array, 0, len(array) - 1)

# Mergesort implementation
def mergesort(array):
    if len(array) > 1:
        mid = len(array) // 2
        left = array[:mid]
        right = array[mid:]

        mergesort(left)
        mergesort(right)

        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                array[k] = left[i]
                i += 1
            else:
                array[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            array[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            array[k] = right[j]
            j += 1
            k += 1

if __name__ == "__main__":
    main()