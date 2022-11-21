CYCLES = 10

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
        print(f"Average sorting time for RECURSIVE RANDOM ELEMENT PIVOT sort: {(avg_sum/CYCLES)*1000}ms")
