import random

def partition_first(arr: list, L: int, H: int) -> int:
        pivot = arr[L]
        pointer = L + 1

        for i in range(H+1):
                if arr[i] < pivot:
                        if j != pointer:
                                swap(arr, pointer, i)
                        pointer += 1
        swap(arr, pointer - 1, L)
        return pointer - 1

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