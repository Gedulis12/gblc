#include "../include/gblc_quicksort.h"

#define TEST_TOTAL 1

int main()
{
    int passed = 0;
    int check = 0;
    int arr_sorted[] = {0, 1, 1, 2, 3, 5, 5, 6, 6, 7, 8, 9};
    int arr[] = {5, 8, 9, 1, 2, 3, 7, 6, 0, 1, 5, 6};

    gblc_quicksort_int(arr, 0, 11);

    for (int i = 0; i < 12; i++)
    {
        if (arr[i] == arr_sorted[i])
        {
            check++;
        }
    }
    //
    // test #1
    if (check == 12)
    {
        passed++;
        printf("test #1 passed\n");
    }
    else
    {
        printf("test #1 failed\n");
    }

    printf("passed %i/%i tests\n---------------\n", passed, TEST_TOTAL);

    if (passed == TEST_TOTAL)
    {
        return 0;
    }

    return 1;
}
