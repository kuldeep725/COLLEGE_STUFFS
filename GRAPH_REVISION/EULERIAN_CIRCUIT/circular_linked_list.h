typedef struct Node {

	int data;
	int *next;

} Node;

void insert (Node *, int);
void freeNode (Node *);
