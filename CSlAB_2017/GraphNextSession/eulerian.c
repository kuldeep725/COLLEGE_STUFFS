/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 10-10-2017
    * Aim       :
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX 32
FILE *fpRead;
int a[32][32];
int n;
char s1[32];

//defining the queue
typedef struct queue {

	int data;
	struct queue *next;

} *queue;

typedef struct path {

    int vertex;
    struct path *next;

} path;

int count = 0;
queue front = NULL;
queue rear = NULL;
//creating the queue with maximum size specified
void createQueue () {
	printf("Empty queue is created with a capacity of %d\n", MAX);		//specifying max size of the queue
}

//inserting value in the rear of the queue
void enQueue (int x) {

	count++;			//increasing size of the queue

	if (count == MAX + 1) {
		//printf("**QUEUE IS FULL**.\n**COULDN'T INSERT NEW ELEMENT IN THE QUEUE**\n");
		count--;		//to compensate unnecessary increase in count
	}

	queue p = (queue) malloc (sizeof(struct queue));	//giiing memory to allocate new queue element
	p->data = x;
    p->next = NULL;
    //printf("p->data = %d\n", p->data);

	//checking if rear is NULL
	if (rear == NULL){
		front = p;
		rear = p;
		front->next = rear;
		rear->next = front;
	}
	else {
		p->next = front;
		rear->next = p;
		rear = p;
	}

}

//deleting value from the front of the queue
int deQueue () {

    queue ptr;
    int value;
    //printf("front->data = %d\n", front->data);
	//checking if the front is null or not%s
	if (front == NULL) {
		//printf("**QUEUE IS EMPTY**\nDEQUEUE OPERATION COULDN'T TAKE PLACE.\n");
		front = NULL;
		rear = NULL;
	}
	//if front is not null else block executes
	else {

		count--;		//decreasing size of the queue
		queue temp = front;
        value= front->data;
		if (front == rear) {
			//printf("----------DELETED ELEMENT IS : %d----------\n", temp->data);
			front = NULL;
			rear = NULL;
			free(temp);
		}
		else {
			front = front->next;
			rear->next = front;
			//printf("----------DELETED ELEMENT IS : %d----------\n", temp->data);
			temp->next = NULL;
			free(temp);
		}

	}
    return value;
}

//checking if the queue is empty or not
int queueIsEmpty () {

	if (front == NULL) {
		//printf("**QUEUE IS EMPTY**\n");
        return 1;
	}
	else {
		//printf("*ELEMENTS ARE PRES%sENT IN THE QUEUE**\n");
        return 0;
	}
}

//to search if root and dest are connected or not
int isNodesConnected (int root, int dest) {

    int checked [32] = {0};     //making all to be unchecked (0)
    createQueue ();             //creating queue

    checked[root] = 1;          //making root as visited
    enQueue (root);
    int i;
    while (!queueIsEmpty()) {
        int currentNode = deQueue ();                           //finding current node
        if (currentNode == dest) {
            return 1;                           //return 1 if the dest is found to be connected to root
        }
        //printf("currentNode = %d\n", currentNode);
        for (i = 0; i < n; i++) {
            //printf("checked[%d] = %d\n", i, checked[i]);
            if (a[currentNode][i] == 1) {
                if (checked[i] != 1) {
                    checked[i] = 1;         //marking node as visited
                    enQueue(i);
                }
            }

        }
    }
    return 0;
}

int haveEdgesLeft () {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                //return 1;
            }
            printf("%d ", a[i][j]);
        }
        printf("\n" );
    }
    return 0;
}


void displayEulerianPath (path *start) {

    path *p = start;
    do {

        printf("%d --> ", p->vertex);
        p = p->next;
    } while (p != start);
    printf("\n");

}

void findEulerianCircuit (path *start, int checked[]) {

    checked[start->vertex] = 1;
    path *p = start;
    path *temp = start;
    front = NULL;
    rear = NULL;
    enQueue (start->vertex);
    int i;
    int j = 0;
    int count;
    do {
        while(!queueIsEmpty()) {
            printf("\n");
            int currentNode = deQueue ();
            int flag = 0;
            int index = 0;
            count = 0;
            printf("currentNode = %d\n", currentNode);
            for (i = 0; i < n; i++) {

                if (a[currentNode][i] == 1) {
                        enQueue(i);
                        p = (path *) malloc(sizeof(path));
                        p->vertex = i;
                        temp->next = p;

                        if (currentNode == start->vertex) {
                            flag = 1;
                        }
                        else {
                            index = i;
                            //printf("temp->vertex = %d\n", temp->vertex);

                        }
                        temp = p;
                        count++;
                        //printf("p->vertex = %d\n", p->vertex);
                }
                /*if (i == n-1 && haveEdgesLeft()) {
                    i = 0;
                }*/
            }
            printf("count = %d\n", count);
            if (flag == 1 && count == 1) {
                a[currentNode][start->vertex] = 0;
                a[start->vertex][currentNode] = 0;
                printf("a[%d][%d] = %d\n", currentNode, start->vertex, a[currentNode][start->vertex]);
            }
            else {
                a[currentNode][index] = 0;
                a[index][currentNode] = 0;
                printf("a[%d][%d] = %d\n", currentNode, index, a[currentNode][index]);
            }
        }
        j++;
        //haveEdgesLeft();
        printf("\n");
    } while (j < 6);

    haveEdgesLeft();
    //if (haveEdgesLeft()) {
        /*enQueue (temp->vertex);
        printf("TEMP->vertex = %d\n", temp->vertex);
        checked[start->vertex] = 0;
        while(!queueIsEmpty()) {
            int currentNode = deQueue ();

            for (i = 0; i < n; i++) {
                if (a[currentNode][i] == 1) {
                    if (checked[i] == 0) {
                        checked[i] = 1;
                        enQueue(i);
                        p = (path *) malloc(sizeof(path));
                        a[currentNode][i] = 0;
                        a[i][currentNode] = 0;
                        p->vertex = i;
                        temp->next = p;
                        temp = p;
                    }
                }
            }
        }
    //}*/
    printf("\n" );
    //displayEulerianPath (start);
    if (!haveEdgesLeft ()) {
        temp->next = start;
        displayEulerianPath (start);
    }

}
void freeNode (path *start) {

    printf("start->vertex = %d\n", start->vertex);
    printf("start->next->vertex = %d\n", start->next->vertex);
    path *p = start->next;
    path *temp;

    do {

        temp = p;
        p = p->next;
        printf("TEMP->vertex = %d\n", temp->vertex);
        temp->next = NULL;
        free(temp);

    } while (p != start);
    // printf("START->vertex = %d\n", start->vertex);
    // free(start);

}
int calculateConnectedComponents (){

	int counter = 0;						//to calculate the number of connected components
	int i,j;
	int z;
	int checked[32] = {0};
	int component[32][32];
	int k[32];
	int last = 0;
	int lastArray[32][32];
	/*printf("Counter before i loop = %d\n", counter);
	printf("n = %d\n", n);*/
	for (i = 0; i < n; i++) {

		// printf("1.counter = %d\n", counter);
		// printf("checked[%d] = %d\n", i, checked[i]);
		if (checked[i] == 1) continue;
		k[counter] = 0;
		counter++;

		// printf("2.counter = %d\n", counter);

		for (j = i+1; j < n; j++) {

			if (checked[j] == 1) continue;
			// printf("checking Nodes between %d and %d : \n", i, j);
			if (isNodesConnected(i,j)) {

				//printf("%d and %d are connected.\n", i, j);
				if (checked[i] != 1) {
					component[counter-1][k[counter-1]]=counter-1;
					//printf("counter[%d][%d] = %d \n", counter-1, k[counter-1], component[counter-1][k[counter-1]]);
					lastArray[counter-1][k[counter-1]]=i;
					k[counter-1]++;
				}
				if (checked[j] != 1) {
					component[counter-1][k[counter-1]]=counter-1;
					//printf("counter[%d][%d] = %d \n", counter-1, k[counter-1], component[counter-1][k[counter-1]]);
					lastArray[counter-1][k[counter-1]]=j;
					k[counter-1]++;
				}
				checked[i] = 1;
				checked[j] = 1;

			}

		}
		// printf("k[%d] = %d\n", counter-1, k[counter-1]);


	}
	//makeDotFileWithDifferentComponents (component, counter, k, lastArray);

	return counter;
}
//to read the file containing adjacency matrix
void readAdjacentMatrix () {

    char s2[32];            //to store input string
    fscanf(fpRead, " %[^\n]s",s1);
    fscanf(fpRead, " %[^\n]s",s2);
    fscanf(fpRead, "%d", &n);       //to read number of rows/columns in the adjacency matrix
    int i, j;               //loop variables
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fpRead, "%1d", &a[i][j]);        //taking input as n*n adjacency matrix from the input file
        }
    }

}

int isDegreeEven () {

    int i,j;
    int sum[32];
    for (i = 0; i < n; i++) {
        sum[i] = 0;
        for (j = 0; j < n; j++) {
            sum[i] += a[i][j];
        }
        if (sum[i] % 2 != 0) {
            return 0;
        }
    }
    return 1;

}

void markAllZeroDegreeVertexAsVisited (int checked[]) {

    int i,j;
    int flag;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                flag = 1;
            }
        }
        if (flag == 0) {
            checked[i] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        printf("checked [%d]= %d\n", i, checked[i]);
    }
}

int main () {

    int startingNode;
    char fileName[55];
    int checked[32] = {0};

	printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);					//asking user for input file name
    fpRead = fopen(fileName,"r");

    printf("Enter the starting Node : \n");
    scanf("%d", &startingNode);
    path *start = (path *) malloc(sizeof(path));
    start->vertex = startingNode;
    start->next = NULL;

    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
    }
    readAdjacentMatrix();					//reading adjacent matrix
    if (isDegreeEven()) {
        printf("Degrees are Even\n");
        markAllZeroDegreeVertexAsVisited (checked);
        if (calculateConnectedComponents() == 1) {
            printf("EULERIAN PATH EXISTS\n");
            findEulerianCircuit (start, checked);
        }

    }
    else {
        printf("%s\n", "Degrees are not even. Not a eulerian graph.");
    }
    if (start != NULL) freeNode(start);
    return 0;
}
