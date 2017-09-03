/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : implementation of circular queue using linked list
    * Date     : 02-09-2017

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack {

	int data;
	struct stack *next;

} stack;

stack *top = NULL;

void stackPush (int);
int stackPop ();
int evaluatePostfix (char *);

int main () {

	char s[100];
	printf("ENTER THE POSTFIX EXPRESSION TO CALCULATE :\n");
	scanf("%s", s);
	int answer = evaluatePostfix (s);
	if (answer == 'w') {
		printf("ENTER VALID EXPRESSION.\n");
		return -1;
	}
	else {
		printf("ANSWER = %d\n", answer);
	}
	
	return 0;

}

void stackPush (int x) {

	stack *p = (stack *) malloc(sizeof(stack));
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

int stackPop () {

	stack *temp;
	int popData = top->data;

	if (top == NULL) {

		printf("EMPTY STACK --> WRONG INPUT EXPRESSION.\n");
		return -1;

	}
	else {

		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);

	}
	return popData;
}

int evaluate (int a, int b, char ch) {

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

int evaluatePostfix (char *s) {

	int r;
	char ch;
	int i = 0;
	int a, b;

	while ((ch = s[i]) != '\0') {

		printf("s[%d] = %c\n", i, ch);

		if (ch >= '0' && ch <= '9') {
			stackPush (ch - '0');
			printf("PUSHED %d\n", ch-'0');
		}
		else {
			b = stackPop ();
			printf("a popped (%d)\n", a);
			a = stackPop ();
			printf("b popped (%d)\n", b);
			if (a != -1 && b != -1) {

				if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
					r = evaluate (a, b, ch);
					stackPush (r);
				}
				else {
					printf("WRONG CHARACTER IN THE EXPRESSION.\n");
					return 'w';
				}
			}
			else {
				break;
			}
				
		}
		printf("TOP = %d\n", top->data);
		i++;
	}

	return stackPop();

}
