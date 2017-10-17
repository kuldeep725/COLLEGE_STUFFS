#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "queue.h"

Queue * createQueue () {       //creates empty queue
    Queue *queue;

    queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->length = 0;

    return queue;
}
//inserting value in the rear of the queue
void enQueue (Queue *queue, int x) {

    struct Info *new = (struct Info *) malloc (sizeof(struct Info));
    new->next = NULL;
    new->data = x;

    if(queue->length == 0)
    {
        queue->front = new;
        queue->rear = new;
        queue->length = 1;
    }
    else
    {
        queue->rear->next = new;
        queue->rear = new;
        queue->length += 1;
    }

}

int deQueue (Queue *queue) {
    int data;
    struct Info *head;

   if(queue->length == 0)
   {
       fprintf(stderr, "ERROR: Attempt to dequeue from an empty queue.\n");
       fprintf(stderr, "       Returned %d.\n", INT_MIN);
       return(INT_MIN);
   }

   head = queue->front;
   data = head->data;

   queue->front = head->next;
   free(head);

   queue->length -= 1;

   if(queue->length == 0)
       queue->rear = NULL;
   return data;
}

//checking if the queue is empty or not
int IsQueueEmpty (Queue *queue) {

	if (queue->rear == NULL) {
		//printf("**QUEUE IS EMPTY**\n");
        return 1;
	}
	else {
		//printf("*ELEMENTS ARE PRES%sENT IN THE QUEUE**\n");
        return 0;
	}
}
