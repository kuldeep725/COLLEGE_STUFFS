/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : To search an element in a circular linked
    * Date     : 08-08-2017

*/
#include<stdio.h>
#include<stdlib.h>

//structure to store data, previous pointer and next pointer
typedef struct node {

	int data;
	struct node *next;
	struct node *prev;

} node;		//creating alias for struct node

//creating the node of size N
node * createNode (int N) {

	node *head = (node *) malloc(sizeof(node));		//giving memory to the head of the node

	int value;
	printf("Enter data : ");
	scanf("%d", &value);		//entering data
	head->data = value;
	head->prev = NULL;
	head->next = NULL;

	node *t = head;

	int i;
	for (i = 1; i < N; i++) {

		scanf("%d", &value);						//entering data
		node *p = (node *) malloc(sizeof(node));
		p->data = value;

		if (i != 1) {
			p->prev = t;					//checking if the element is head or not
		}

		t->next = p;
		t = p;

	}

	head->prev = t;			//setting head->prev to last element
	t->next = head;			//setting last element->next to head of the node
	return head;		//returning head pointer

}

//display the data of the node
void display (node *head) {

	node *p = head;

	do {

		printf("Data : %d\n", p->data);
		p = p->next;

	} while (p != head);

}

//checking if the element is there or not in the list
int IsElementThere (node *head, int ele) {

	node *p = head;
	int success = 0;

	do {
		if (p->data == ele) {		//check if element is equal to the data in the node 
			success = 1;
			break;
		}
		p = p->next;

	} while (p != head);

	return success;			//return 1 if elements exists, 0 otherwise

}

//function to free all the memory
void freeMemory (node *head) {

    node *p = head->next;
    node *temp;

    do {

        temp = p;			//storing p in temporary pointer 'temp'
        p = p->next;		//going to next pointer 
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);			//free up the memory

    } while (p != head);

    free(head);		//freeing head at the last since head is needed in the loop condition

}

//MAIN FUNCTION BEGINS
int main () {

	int N;
	printf("Enter the number of elements : \n");
	scanf("%d", &N);
	node *head = createNode(N);			//creating the Node
	display (head);

	int searchElement;
	printf("ENTER THE SEARCH ELEMENT : \n");
	scanf("%d", &searchElement);			//entering the search Element
	printf("SEARCHING THE ELEMENT %d IN THE LIST : \n", searchElement);
	printf("...\n");
	printf("...\n");
	if (IsElementThere (head, searchElement)) {			//checking if the element exists or not

		printf("BINGO  !! The element %d exists.\n", searchElement);

	}
	else {
		printf("SORRY !! The element %d doesn't exist.\n", searchElement);
	}
	if (head != NULL) {			//checking if the head is NULL or not
		freeMemory (head);		//free the memory
	}	

	return 0;

}
//MAIN FUNCTION ENDS