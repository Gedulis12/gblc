#ifndef GBLC_QUEUE_H
#define GBLC_QUEUE_H

#include <string.h>

struct gblc_qnode {
    struct gblc_qnode *next;
    void *data;
    size_t size;
};

struct gblc_queue {
    struct gblc_qnode *head;
    struct gblc_qnode *tail;
    int len;
};

struct gblc_queue* gblc_queue_create();
int gblc_queue_enqueue(struct gblc_queue *queue, const void *newval, size_t size);
int gblc_queue_is_empty(struct gblc_queue *queue);
void gblc_queue_free(struct gblc_queue *queue);
void* gblc_queue_peek(struct gblc_queue *queue);
int gblc_queue_dequeue(struct gblc_queue* queue);


#endif
