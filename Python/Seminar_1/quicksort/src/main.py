import random
FIRST = 0
MEDIAN = 1
RANDOM = 2

def partition_last(arr: list, L: int, H: int):
        pivot = arr[H]
        pointer = L - 1

        for i in range(H+1):
                if arr[j] < pivot:
                        swap(arr, pointer, i)
                        pointer += 1            # attention
        swap(arr, pointer + 1, H)
        return pointer + 1

def partition_median(arr: list, L: int, H: int):
        M = (L + H) // 2
        median = median_three(arr, L, H, M)
        
        if median > M:
                return partition_last(arr, L, H)
        elif median < M:
                return partition_first(arr, L, H)
        if arr[M] < arr[L]:
                swap(arr, M, L)
        if arr[H] < arr[L]:
                swap(arr, H, L)
        if arr[H] < arr[M]:
                swap(arr, H, M)
        
        swap(arr, M, H-1)
        return partition_last(arr, L, H)

def partition_random(arr: list, L: int, H: int):
        r = random.randrange(1000000)
        swap(arr, random, H)
        return partition_first(arr, L, H)

def swap(arr: list, L: int, H: int):
        temp = x
        arr[x] = arr[y]
        arr[y] = temp

def recursive_quicksort(pivot_type: int, arr: list, L: int, H: int):
        if L < H:
                if pivot_type == FIRST:
                        pivot = partition_first(arr, L, H)
                if pivot_type == MEDIAN:
                        pivot = partition_median(arr, L, H)
                if pivot_type == RANDOM:
                        pivot = partition_random(arr, L, H)

def measure_quicksort_recursive_first_pivot(arr, ref):
        avg_sum = 0
        for _ in range(CYCLES):
                l = time.time()
                quick_sort_recursive_first_pivot(arr, 0, len(arr)-1)
                h = time.time()
                avg_sum += (h-l)
                print(arr)
                arr = ref
        print(f"Average sorting time for RECURSIVE FIRST ELEMENT PIVOT sort: {(avg_sum/CYCLES)*1000}ms")

def measure_quicksort_recursive_median_pivot(arr, ref):
        avg_sum = 0
        for _ in range(CYCLES):
                start = time.time()
                quick_sort_recursive_first_pivot(arr, 0, len(arr)-1)
                end = time.time()
                avg_sum += (end-start)
                arr = ref
        print(f"Average sorting time for RECURSIVE MEDIAN OF THREE ELEMENT PIVOT sort: {(avg_sum/CYCLES)*1000}ms")

def measure_quicksort_recursive_random_pivot(arr, ref):
        avg_sum = 0
        for _ in range(CYCLES):
                l = time.time()
                quick_sort_recursive_first_pivot(arr, 0, len(arr)-1)
                h = time.time()
                avg_sum += (h-l)
                arr = ref
        print(f"Average sorting time for RECURSIVE RANDOM ELEMENT PIVOT sort: {avg_sum/CYCLES*1000}ms")
