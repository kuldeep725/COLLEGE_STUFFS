/*  
    C code to implement a simple queue of integers using a linked list.
    Deepak R
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "queue.h"

struct q_int* create_q_int() // Creates and empty queue
{
    struct q_int *queue;

    queue = (struct q_int *) malloc(sizeof(struct q_int));
    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;

    return queue;
}

void enqueue_q_int(struct q_int *queue, int value)
{
    struct s_int *new;

    // Memory for the new item
    new  = (struct s_int *) malloc(sizeof(struct s_int));
    new->next = NULL;
    new->data = value;

    if(queue->length == 0)
    {
        queue->head = new;
        queue->tail = new;
        queue->length = 1;
    }
    else
    {
        queue->tail->next = new;
        queue->tail = new;
        queue->length += 1;
    }
}

int dequeue_q_int(struct q_int *queue)
{
    int data;
    struct s_int *orig_head;

    if(queue->length == 0)
    {
        fprintf(stderr, "ERROR: Attempt to dequeue from an empty queue.\n");
        fprintf(stderr, "       Returned %d.\n", INT_MIN);
        return(INT_MIN);
    }

    orig_head = queue->head;
    data = orig_head->data;

    queue->head = orig_head->next;
    free(orig_head);
    
    queue->length -= 1;

    if(queue->length == 0)
        queue->tail = NULL;
    return data;
}

void print_q_int(struct q_int *queue)
{
    struct s_int *current;

    current = queue->head;

    printf("Queue Contents:\t");

    while(current != NULL)
    {
        printf("%d, ", current->data);
        current = current->next;
    } 
    printf("\n");

}
void flush_q_int(struct q_int *queue)
{
    int temp;
    while(queue->head != NULL)
    {
        temp = dequeue_q_int(queue);
    } 
}


