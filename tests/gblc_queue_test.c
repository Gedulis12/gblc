#include "gblc_queue.h"
#include <stdio.h>

#define TEST_TOTAL 7
#define TEST_STR "Giedrute"
#define TEST_INT 42

int main()
{
    int passed = 0;

    // test #1
    struct gblc_queue *queue = gblc_queue_create();
    if (queue != NULL)
    {
        passed ++;
        printf("test #1 passed\n");
    }
    else
    {
        printf("test #1 failed\n");
    }

    char *value = TEST_STR;
    int value2 = TEST_INT;

    char *check;
    int *check2;

    // test #2
    if (gblc_queue_is_empty(queue) == 1)
    {
        passed ++;
        printf("test #2 passed\n");
    }
    else
    {
        printf("test #2 failed\n");
    }

    // test #3
    gblc_queue_enqueue(queue, value, sizeof(char) * strlen(value));

    check = (char*)gblc_queue_peek(queue);
    if (strcmp(check, TEST_STR) == 0)
    {
        passed ++;
        printf("test #3 passed\n");
    }
    else
    {
        printf("test #3 failed\n");
    }

    // test #4
    gblc_queue_enqueue(queue, &value2, sizeof(value2));
    check = (char*)gblc_queue_peek(queue);
    if (strcmp(check, TEST_STR) == 0)
    {
        passed ++;
        printf("test #4 passed\n");
    }
    else
    {
        printf("test #4 failed\n");
    }

    // test #5
    gblc_queue_dequeue(queue);
    if (queue->len == 1)
    {
        passed ++;
        printf("test #5 passed\n");
    }
    else
    {
        printf("test #5 failed\n");
    }

    // test #6
    check2 = (int*)gblc_queue_peek(queue);
    if (*check2 == TEST_INT)
    {
        passed ++;
        printf("test #6 passed\n");
    }
    else
    {
        printf("test #6 failed\n");
    }

    // test #7
    gblc_queue_free(queue);
    if (gblc_queue_is_empty(queue))
    {
        passed ++;
        printf("test #7 passed\n");
    }
    else
    {
        printf("test #7 failed\n");
    }

    printf("passed %i/$i tests\n---------------\n", passed, TEST_TOTAL);

    if (passed == TEST_TOTAL)
    {
        return 0;
    }

    return 1;
}
