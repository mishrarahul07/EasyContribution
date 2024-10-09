def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)

    swap(arr, i + 1, high)
    return i + 1

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def quick_sort(arr, low, high):
    if low < high:
        pivot_index = partition(arr, low, high)
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)

if __name__ == "__main__":
    arr = [32, 71, 12, 45, 26, 80, 53]
    quick_sort(arr, 0, len(arr) - 1)
    
    print("Sorted array:")
    for val in arr:
        print(val, end=" ")
