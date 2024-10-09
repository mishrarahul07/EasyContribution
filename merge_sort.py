def merge(arr, left, mid, right):
    left_size = mid - left + 1
    right_size = right - mid

    left_half = [0] * left_size
    right_half = [0] * right_size

    for i in range(left_size):
        left_half[i] = arr[left + i]
    for j in range(right_size):
        right_half[j] = arr[mid + 1 + j]

    i = 0
    j = 0
    k = left

    while i < left_size and j < right_size:
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
        k += 1

    while i < left_size:
        arr[k] = left_half[i]
        i += 1
        k += 1

    while j < right_size:
        arr[k] = right_half[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

def print_list(arr):
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    arr = [42, 23, 17, 99, 8, 56, 74, 3]
    print("Given array:")
    print_list(arr)

    merge_sort(arr, 0, len(arr) - 1)

    print("\nSorted array:")
    print_list(arr)
