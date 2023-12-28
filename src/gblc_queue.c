#include "gblc_queue.h"
#include <stdio.h>
#include <stdlib.h>

void* gblc_queue_peek(struct gblc_queue *queue)
{
    if (!gblc_queue_is_empty(queue))
    {
        return queue->head->data;
    }

    return NULL;
}

int gblc_queue_dequeue(struct gblc_queue* queue)
{
    if (gblc_queue_is_empty(queue))
    {
        return 1;
    }

    queue->len--;
    struct gblc_qnode *temp = queue->head;
    queue->head = temp->next;
    free(temp);

    return 0;
}

struct gblc_queue* gblc_queue_create()
{
    struct gblc_queue *queue = (struct gblc_queue*)malloc(sizeof(struct gblc_queue));
    if(!queue)
    {
        printf("Memory allocation failed for the queue.\n");
        return NULL;
    }
    queue->head = queue->tail = NULL;
    queue->len = 0;
    return queue;
}

int gblc_queue_enqueue(struct gblc_queue *queue, const void *data, size_t size)
{
    struct gblc_qnode *node = (struct gblc_qnode*)malloc(sizeof *node);
    if (!node)
    {
        printf("Memory allocation failed for a new node.\n");
        return 1; //malloc for node failed
    }

    node->data = malloc(size);
    if (node->data == NULL)
    {
      free(node);
      return 2; //malloc for data failed
    }

    if ((memcpy(node->data, data, size) == NULL))
    {
        return 3; //memcpy of data failed
    }
    else
    {
        node->size = size;
        node->next = NULL;
    }

    if (gblc_queue_is_empty(queue))
    {
        queue->head = queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->len++;

    return 0;
}

int gblc_queue_is_empty(struct gblc_queue *queue)
{
    return queue->len == 0;
}

void gblc_queue_free(struct gblc_queue *queue)
{
    while (!gblc_queue_is_empty(queue))
    {
        gblc_queue_dequeue(queue);
    }
    free(queue);
}
