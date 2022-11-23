#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

void insertionsort(long *arr, long COLLECTION_SIZE)
{
        int i = 1, j;
        while (i < COLLECTION_SIZE)
        {
                int temp = arr[i];
                j = i;
                while (j > 0 && arr[j - 1] > temp)
                {
                        arr[j] = arr[j - 1];
                        j = j - 1;
                }
                arr[j] = temp;
                i = i + 1;
        }
}


/*
procedure insertion_sort(array : list of sortable items, n : length of list)
    i ← 1
    while i < n
        temp ← array[i]
        j ← i
        while j > 0 and array[j - 1] > temp
            array[j] ← array[j - 1]
            j ← j - 1
        end while
        array[j] ← temp
        i ← i + 1
    end while
end procedure 
*/