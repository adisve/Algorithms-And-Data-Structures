#include <stdio.h>
#include "quicksort.h"
#include "measurement.h"

void measure_recursive_quicksort(int *arr, int *reference_arr, int collection_size, int type)
{
        double average_rec_first = first_quicksort(arr, reference_arr, collection_size, type);
        double average_rec_random = random_quicksort(arr, reference_arr, collection_size, type);
        double average_rec_median_three = median_three_quicksort(arr, reference_arr, collection_size, type);

        printf("\n\n---- Results for RECURSIVE quick sort algorithm (Median of three element pivot, Random element pivot, First element pivot) ----\n\n");
        printf("\n\nPivot element: Median of three\nExecution time for collection size of %d: %.16fms\n", collection_size, average_rec_median_three*1000);
        printf("\n\nPivot element: Random\nExecution time for collection size of %d: %.16fms\n", collection_size, average_rec_random*1000);
        printf("\n\nPivot element: First\nExecution time for collection size of %d: %.16fms\n", collection_size, average_rec_first*1000);
}