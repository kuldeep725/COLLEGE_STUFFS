#include<stdio.h>
#include<stdlib.h>
#include "circular_linked_list.h"

Node * createCircularLinkedList (Node *head) {

	head = (Node *) malloc(sizeof(Node));
	head->data = -1;
	head->next = NULL;

	return head;
}
void insert (Node *head, int data) {

	head->

}