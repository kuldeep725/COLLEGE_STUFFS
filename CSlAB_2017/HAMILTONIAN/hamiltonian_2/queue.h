//defining the queu
struct Info {

	int data;
	struct Info *next;

} ;
typedef struct Queue {
    struct Info *front;
    struct Info *rear;
    int length;
} Queue;

Queue * createQueue ();
void enQueue (Queue *, int);
int deQueue (Queue *);
int IsQueueEmpty (Queue *);
