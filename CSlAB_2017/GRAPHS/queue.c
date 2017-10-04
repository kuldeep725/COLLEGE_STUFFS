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

queue front = NULL;			//creating pointer pointing to the front of the queue
queue rear = NULL;			//creating pointer pointing to the last of the queue

int count = 0;				//for counting the current total size of the queue

//DECLARING PROTOTYPES
void createQueue ();
void enQueue (int);
void deQueue ();
void queueIsEmpty ();
void queueFront ();
void queueSize ();
void displayQueue ();

//MAIN BEGINS HERE
int main () {

	int choice;
	int value;

	
    while(1)
    {
    	//CREATING MENU DISPLAY
        printf("\n----------ENTER YOUR CHOICE---------- \n");
        printf("1 : CREATE AN EMPTY QUEUE \n2 : ENQUEUE AN ELEMENT\n");
        printf("3 : DEQUEUE AN ELEMENT \n4 : CHECK IF EMPTY\n");
        printf("5 : GET THE FIRST ELEMENT OF THE QUEUE\n");
        printf("6 : PRINT THE PRESENT SIZE OF THE QUEUE\n");
        printf("7 : PRINT ALL THE ELEMENTS IN THE QUEUE\n");
        printf("0 : EXIT\n");
        printf("-->");
        scanf("%d", &choice);		//asking user to enter his choice

        switch (choice)    // menu driven program
        {

	        case 1: 
	            createQueue();		//creating the queue with maximum size specified
	            break;

	        case 2:    
	        	printf("Enter the element to be inserted in the queue : \n");
	        	scanf("%d", &value);
	            enQueue(value);		//inserting value in the rear of the queue
	            break;

	        case 3: 
	            deQueue();			//deleting value from the front of the queue
	            break;

	        case 4: 
	            queueIsEmpty();		//checking if the queue is empty or not
	            break;

	        case 5: 
	            queueFront();		//to display front of the queue
	            break;

	        case 6: 
	            queueSize();		//to display current size of the queue
	            break;

	        case 7:
	        	displayQueue();		//to display entire queue by deleting all the elements sequentially
	        	break;

	        case 0: 
	            exit(0);			//exiting the loop

	        default: 
	            printf("WRONG CHOICE\n");		//when choice is not option
	            break;
        }
    }

	return 0;

}

//creating the queue with maximum size specified
void createQueue () {
	printf("Empty queue is created with a capacity of %d\n", MAX);		//specifying max size of the queue
}

//inserting value in the rear of the queue
void enQueue (int x) {

	count++;			//increasing size of the queue

	if (count == MAX + 1) {
		printf("**QUEUE IS FULL**.\n**COULDN'T INSERT NEW ELEMENT IN THE QUEUE**\n");
		count--;		//to compensate unnecessary increase in count
	}

	queue p = (queue) malloc (sizeof(struct queue));	//giiing memory to allocate new queue element
	p->data = x;

	//checking if rear is NULL
	if (rear == NULL) {
		front = p;
		rear = p;
		front->next = rear;
		rear->next = front;
	} 
	else {
		p->next = front;
		rear->next = p;
		rear = p;
	}

}

//deleting value from the front of the queue
void deQueue () {

	//checking if the front is null or not	
	if (front == NULL) {		
		printf("**QUEUE IS EMPTY**\nDEQUEUE OPERATION COULDN'T TAKE PLACE.\n");
		front = NULL;
		rear = NULL;
	}
	//if front is not null else block executes
	else {

		count--;		//decreasing size of the queue
		queue temp = front;
		if (front == rear) {
			printf("----------DELETED ELEMENT IS : %d----------\n", temp->data);
			front = NULL;
			rear = NULL;
			free(temp);
		}
		else {
			front = front->next;
			rear->next = front;
			printf("----------DELETED ELEMENT IS : %d----------\n", temp->data);
			temp->next = NULL;
			free(temp); 
		}
		
	}
}

//checking if the queue is empty or not
void queueIsEmpty () {

	if (front == NULL) {
		printf("**QUEUE IS EMPTY**\n");
	}
	else {
		printf("*ELEMENTS ARE PRESENT IN THE QUEUE**\n");
	}
}

void queueFront () {

	if (front == NULL) {
		printf("**QUEUE IS EMPTY**\n");
	}
	else {
		printf("FRONT->%d\n", front->data);
	}

}

//to display current size of the queue
void queueSize () {

	printf("CURRENT SIZE OF THE QUEUE IS : %d\n", count);

}

//to display entire queue by deleting all the elements sequentially (front to rear)
void displayQueue () {

	int t = count;
	while (t--) {
		queueFront();
		deQueue();
	}
	count = 0;

 }
