def median_three(arr: list, a: int, b: int, c: int):
        if ((arr[a] > arr[b]) ^ (arr[a] > arr[c])):
                return a
        elif ((arr[b] < arr[a]) ^ (arr[b] < arr[c])):
                return b
        else:
                return c