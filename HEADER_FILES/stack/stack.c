#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include "stack.h"

Stack * createStack () {

	Stack *stack = (Stack *) malloc (sizeof (Stack));

	stack->top = NULL;
	stack->length = 0;

	return stack;

}

void push (Stack *stack, int ele) {

	Info *new = (Info *) malloc (sizeof(Info));
	new->data = ele;

	if (stack->top == NULL) {

		stack->top = new;
		stack->top->next = NULL;
		stack->length = 1;

	}

	else {

		new->next = stack->top;
		stack->top = new;
		stack->length += 1;

	}

}

int pop (Stack *stack) {

	if (stack->length == 0) {

		printf("STACK UNDERFLOW...\n");
		printf("RETURNED %d\n", INT_MIN);
		return INT_MIN;

	}
	
	Info *top_m = stack->top;
	int item = stack->top->data;

	stack->top = stack->top->next;

	free (top_m);
	stack->length--;

	if (stack->length == 0) stack->top = NULL;

	return item;

}

int isStackEmpty (Stack *stack) {

	return stack->length;

}