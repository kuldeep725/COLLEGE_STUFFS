#include<stdio.h>
#include<stdlib.h>

typedef struct node {

	int data;
	struct node *next;
	struct node *prev;

} node;

node * createNode (int N) {

	node *head = (node *) malloc(sizeof(node));

	int value;
	scanf("%d\n", &value);
	head->data = value;
	head->prev = NULL;
	head->next = NULL;

	node *t = head;

	int i;
	for (i = 1; i < N; i++) {

		scanf("%d\n", &value);
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
	return head;

}

void display (node *head) {

	node *p = head;
	
	do {

		printf("Data : %d\n", p->data);
		p = p->next;

	} while (p->next != head);

} 

int IsElementThere (node *head, int ele) {

	node *p = head;
	int success = 0;

	do {
		if (p->data == ele) {
			success = 1;
			break;
		}
		p = p->next;

	} while (p->next != head);

	return success;

}

int main () {

	int N = 5;
	node *head = createNode(N);
	display (head);

	int searchElement;
	scanf("%d\n", &searchElement);

	if (IsElementThere (head, searchElement)) {

		printf("BINGO  !! The element %d exists.\n", searchElement);

	}
	else {
		printf("SORRY !! The element %d doesn't exist.\n", searchElement);
	}

	return 0;

}