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

} node;

//creating the node
node * createNode (int N) {

	node *head = (node *) malloc(sizeof(node));

	int value;
	printf("Enter data : ");
	scanf("%d", &value);
	head->data = value;
	head->prev = NULL;
	head->next = NULL;

	node *t = head;

	int i;
	for (i = 1; i < N; i++) {

		scanf("%d", &value);
		node *p = (node *) malloc(sizeof(node));
		p->data = value;

		if (i != 1) {
			p->prev = t;		
		}

		t->next = p;
		t = p;

	}

	head->prev = t;
	t->next = head;
	return head;		//returning head pointer

}

//display the data
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
		if (p->data == ele) {
			success = 1;
			break;
		}
		p = p->next;

	} while (p != head);

	return success;			//return 1 if elements exists, 0 otherwise

}

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
	if (IsElementThere (head, searchElement)) {

		printf("BINGO  !! The element %d exists.\n", searchElement);

	}
	else {
		printf("SORRY !! The element %d doesn't exist.\n", searchElement);
	}

	return 0;

}
