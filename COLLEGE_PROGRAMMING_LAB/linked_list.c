#include<stdio.h>
#include<stdlib.h>
struct Node {

	int data;
	struct Node *next;		// Pointer to next node in DLL

};

struct Node * createNode (int n) {

	struct Node *p = (struct Node *) malloc(sizeof(struct Node));
	scanf("%d", &(p->data));
	p->next = NULL;

	struct Node *head = p;
	struct Node *temp = p;

	int i;
	for (i = 1; i < n; i++) {

		struct Node *p = (struct Node *) malloc(sizeof(struct Node));
		scanf("%d", &(p->data));
		temp->next = p;
		temp = p;

	}

	temp->next = NULL;

	return head;

}

void insertNode(struct Node *head, int val, int newItem) {

	struct Node *newPtr = (struct Node *) malloc(sizeof(struct Node));
	newPtr->data = newItem;
	newPtr->next = NULL;

	struct Node *temp = head;

	for (p = head; p != NULL; p = p->next) {

		if (p == val) {
			temp->next = newPtr;
			newPtr->next = p;
			break;
		}
		temp = p;

	}

}

void displayList (struct Node *head) {

	struct Node *p;
	for (p = head; p != NULL; p++) {
		printf("%d\n", p->data);
	}

}
int main () {

	int N;
	int i;

	scanf("%d",&N);

	struct Node *head = createNode(N);

	int val;
	int newItem;
	scanf("%d", &val);
	scanf("%d", &newItem);

	insertNode(head, val,newItem);
	printf("head->data : %d\n", head->data);
	printf("head->next->data : %d\n", head->next->data);
	return 0;

}