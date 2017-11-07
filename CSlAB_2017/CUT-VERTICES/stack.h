//headerfile for stacks

typedef struct InfoStack {

	int data;
	struct InfoStack *next;

} InfoStack;

typedef struct Stack {

	struct InfoStack *top;
	int length;

} Stack;

Stack * createStack ();
void push (Stack *, int);
int pop (Stack *);
int isStackEmpty (Stack *);
