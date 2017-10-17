/*
    Header file for queue.c
*/

// ** Data Structures 

// One node of the queue (to be implemented as a linked list)
struct s_int        
{
    int data;
    struct s_int *next;
};


// A queue data structure 
// Implemented as a linked list along with pointers to the
// first and last nodes in the list
struct q_int       
{
    struct s_int *head; // NULL if empty, points to first-in node o/w
    struct s_int *tail; // NULL if empty, points to last-in node o/e
    int length;
};

// ** Function prototypes

// Function to create an empty queue and return a pointer to it
struct q_int* create_q_int(); 

// Function to enqueue a passed item to the tail of the queue
void enqueue_q_int(struct q_int *queue, int value);

// Function to dequeue and return the item from the head of the queue
int dequeue_q_int(struct q_int *queue);

// A helper function to print the entire contents of the queue
void print_q_int(struct q_int *queue);

// A function to clear all the dynamic memory allocated for the queue
void flush_q_int(struct q_int *queue);

