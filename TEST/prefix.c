/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : evaluation of postfix expression
    * Date     : 03-09-2017

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//creating stack
typedef struct stack {

	int data;
	struct stack *next;

} stack;				//creating an alias for struct stack

stack *top = NULL;		//declaring top pointer of the stack pointing to the top element of the stack

//DECLARING PROTOTYPES
void stackPush (int);			//to push an element in the stack
int stackPop ();				//to pop an element from the stack
int evaluatePostfix (char *);	//to evaluate postfix expression
int evaluate (int, int, char);	//to check the operator and evaluate two numbers with that operator

int main () {

	char s[100];				//for storing postfix expression
	printf("ENTER THE POSTFIX EXPRESSION TO CALCULATE :\n");
	scanf("%s", s);
	int answer = evaluatePostfix (s);		//calling evaluatePostfix function to give the value of the expression
	
	//checking whether the equation entered is valid or not
	if (answer == 'w') {					
		printf("ENTER VALID EXPRESSION.\n");
		return -1;
	}
	else {
		//if the equation is valid then the answer is
		printf("ANSWER = %d\n", answer);
	}
	
	return 0;

}

//to push an element in the stack
void stackPush (int x) {

	stack *p = (stack *) malloc(sizeof(stack));		//giving memory to the pointer to store element of the stack
	p->data = x;
	p->next = NULL;

	if (top == NULL) {
		top = p;
	}
	
	else {

		p->next = top;
		top = p;

	}

}

//to pop an element from the stack
int stackPop () {

	stack *temp;
	int popData = top->data;

	//checking if the top pointer is null or not
	if (top == NULL) {

		printf("EMPTY STACK --> WRONG INPUT EXPRESSION.\n");
		return -1;

	}
	else {

		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);			//deleting the element from the memory

	}
	return popData;			//returning the popped element 
}

//to check the operator and evaluate two numbers with that operator
int evaluate (int a, int b, char ch) {

	//checking the operator using switch statement
	switch (ch) {

		case '+' :
			return (a + b);
		case '-' :
			return (a - b);
		case '*' :
			return (a * b);
		case '/' :
			return (a / b);

	}

}

//to evaluate postfix expression
int evaluatePostfix (char *s) {

	int r;
	char ch;
	int i = 0;
	int a, b;
	int length = strlen(s);
	
	while (i < length) {
	
		ch = s[length - 1 - i]);
		//printf("s[%d] = %c\n", i, ch);

		if (ch <= '0' && ch >= '9') {
			stackPush (ch - '0');
		}
		else {
			b = stackPop ();		//popping top element from the stack
			a = stackPop ();		//popping new top element from the stack

			//checking whether top is NULL or not
			if (a != -1 && b != -1) {

				if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
					r = evaluate (a, b, ch);
					stackPush (r);			//pushing new operated value in the top of the stack
				}
				else {
					printf("WRONG CHARACTER IN THE EXPRESSION.\n");		//if wrong operator is entered
					return 'w';
				}
			}
			else {
				break;
			}
				
		}
		i++;
	}

	return stackPop();		//return stackPop

}
