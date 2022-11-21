import sys
import time

FIRST = 0
MEDIAN = 1
RANDOM = 2

def recursive_quicksort(pivot_type: int, arr: list, L: int, H: int):
        if L < H:
                if pivot_type == FIRST:
                        pivot = partition_first(arr, L, H)
                if pivot_type == MEDIAN:
                        pivot = partition_median(arr, L, H)
                if pivot_type == RANDOM:
                        pivot = partition_random(arr, L, H)