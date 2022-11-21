#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

void insertionsort(int *arr, int size)
{
        int key;
        int comp_index;
        for(int i = 1; i < size; i++)
        {
                /* Set current index of iteration to be key, loop always
                 * starts from second element in array (arr[1]) since we assume the
                 * first two elements to always be sorted */
                key = arr[i];
                /* Set comparator index to be the element on left of the current key
                 * in this iteration, spanning from 1 to the size of [arr] */
                comp_index = i - 1;

                /* While the key element is less than the one currently on the
                 * left of [key] AND we haven't hit the beginning of [arr],
                 * essentially compare [key] with each element on the left of [key] 
                 * until an element smaller than [key] is found.*/
                while(key < arr[comp_index] && comp_index >= 0)
                {
                        /* Assign the value to the right of arr[comp_index] to be
                         * what arr[comp_index] currently is */
                        arr[comp_index + 1] = arr[comp_index];
                        /* Decrement comparator index value to shift it left */
                        --comp_index;
                }
                /* After each for loop iteration has finished, set the key value
                 * to be in its correct position [arr] */
                arr[comp_index + 1] = key;
        }
}