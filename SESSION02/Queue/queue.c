/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : implementation of circular queue using linked list
    * Date     : 02-09-2017

*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct queue {

	int data;
	struct queue *next;

} *queue;

int count = 0;

int main () {

	queue front = NULL;
	queue rear = NULL;
	int choice;
	int value;

	
    while(1)
    {
        printf("ENTER THE CHOICE \n");
        printf("1 : CREATE AN EMPTY QUEUE \n2 : ENQUEUE AN ELEMENT\n");
        printf("3 : DEQUEUE AN ELEMENT \n4 : CHECK IF EMPTY\n");
        printf("5. GET THE FIRST ELEMENT OF THE QUEUE\n");
        printf("6. GET THE NUMBER OF ENTRIES IN THE QUEUE\n");
        printf("7. PRINT ALL THE ELEMENTS IN THE QUEUE\n");
        printf("8. EXIT\n");
        scanf("%d", &choice);

        switch (choice)    // menu driven program
        {

	        case 1: 
	            printf("Empty queue is created with a capacity of %d\n", MAX);
	            break;

	        case 2:    
	        	printf("Enter the element to be inserted in the queue : \n");
	        	scanf("%d", &value);
	            enQueue(&rear, value);
	            break;

	        case 3: 
	            deQueue(&front);
	            break;
	        case 4: 

	            queueIsEmpty(&front);
	            break;

	        case 5: 
	            queueFront(&front);
	            break;

	        case 6: 
	            queue_size();
	            break;

	        case 7:
	        	displayQueue(&front);
	        	break;

	        case 8: 
	            exit(0);

	        default: 
	            printf("WRONG CHOICE\n");
	            break;
        }
    }

	return 0;

}