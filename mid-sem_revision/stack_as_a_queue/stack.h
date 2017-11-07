//headerfile for stacks

typedef struct Info {

	int data;
	struct Info *next;

} Info;

typedef struct Stack {

	struct Info *top;
	int length;

} Stack;

Stack * createStack ();
void push (Stack *, int);
int pop (Stack *);
int isStackEmpty (Stack *);