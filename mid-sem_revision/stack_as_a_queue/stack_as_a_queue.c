#include "stack.h"
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int next (Stack *stack, Stack *stack_d) {
	
	int last_pno;
	int t_ele;
	
	if (isStackEmpty(stack)) {

		printf("NO CAR IN THE LIST.\n");
		return INT_MIN;
	
	}

	while (!isStackEmpty(stack)) {

		t_ele = pop (stack);
		push (stack_d, t_ele);

	}

	last_pno = pop (stack_d);
	// printf("last_pno = %d\n", last_pno);

	while (!isStackEmpty(stack_d)) {

		t_ele = pop (stack_d);
		push (stack, t_ele);

	}

	return last_pno;

}

void display (Stack *stack, Stack *stack_d) {

	int t_ele;

	while (!isStackEmpty(stack)) {

		t_ele = pop (stack);
		push (stack_d, t_ele);

	}

	while (!isStackEmpty(stack_d)) {

		t_ele = pop (stack_d);
		printf("CAR %d  ", t_ele);
		push (stack, t_ele);

	}

	printf("\n");

}

int main () {

	int choice;
	int plateNumber;
	int last_plate_number;

	Stack *stack = createStack ();
	Stack *stack_d = createStack ();

	do {

		printf("\n-----THIS IS AUTO-MOBILE REGISTER SERVICE-----\n");
		printf("1. INSERT\n");
		printf("2. NEXT\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");

		printf("YOUR CHOICE -> ");
		scanf ("%d", &choice);

		switch (choice) {

			case 1 : 
					printf("\nenter the platenumber : ");
					scanf ("%d", &plateNumber);

					push (stack, plateNumber);
					printf("\n***platenumber %d is now in the list.***\n", plateNumber);
					break;

			case 2 : 
					last_plate_number = next (stack, stack_d);

					if (last_plate_number != INT_MIN) {

						printf("\n***car with platenumber %d is to be serviced next.***\n", last_plate_number);
						printf("***servicing of car with platenumber %d is done.***\n", last_plate_number);
						
					}
					
					break;

			case 3 : 
					display (stack, stack_d);
					break;

			case 4 : 
					printf("exiting...\n");
					choice = 4;
					break;

			default :
					printf("enter valid choice only...\n");

		}

	} while (choice != 4);

	return 0;

}