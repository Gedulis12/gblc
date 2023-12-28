#include "../include/gblc_quicksort.h"

static int gblc_qs_partition(int unsorted_arr[], int low, int high);

int gblc_quicksort_int(int unsorted_arr[], int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int pivot_idx = gblc_qs_partition(unsorted_arr, low, high);
    gblc_quicksort_int(unsorted_arr, low, pivot_idx - 1);
    gblc_quicksort_int(unsorted_arr, pivot_idx + 1, high);
    return 0;
}

static int gblc_qs_partition(int unsorted_arr[], int low, int high)
{
        int pivot = unsorted_arr[high];
        int idx = low - 1;

        for (int i = low; i < high; i++)
        {
            if (unsorted_arr[i] <= pivot)
            {
                idx ++;
                int temp = unsorted_arr[i];
                unsorted_arr[i] = unsorted_arr[idx];
                unsorted_arr[idx] = temp;
            }
        }
        idx ++;
        unsorted_arr[high] = unsorted_arr[idx];
        unsorted_arr[idx] = pivot;

        return idx;
}
