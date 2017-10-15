/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 10-10-2017
    * Aim       : To find Eulerian Circuit of a given adjacent matrix if Eulerian Circuit exists
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX 40
#define NOC 6			//number of colors

FILE *fpRead;
FILE *fpWrite;

int a[32][32];
int n;
char s1[32];


//defining the queue
typedef struct queue {

	int data;
	struct queue *next;

} *queue;

int count = 0;
queue front = NULL;
queue rear = NULL;
//creating the queue with maximum size specified
void createQueue () {
	//printf("Empty queue is created with a capacity of %d\n", MAX);		//specifying max size of the queue
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

//to make dot file from the given adjacency matrix
void makePlanarDotFile (char color[][20], int colorArray[]) {

    char one[32];
    strcpy(one, s1);
    char str[32];
   	strcpy(str, s1);
    strcat(str, "ColoredPlanar.dot");
    fpWrite = fopen(str, "w");                   //creating/ opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    int i,j;
    int check;

    for (i = 0; i < n; i++) {
        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        for (j = i; j < n; j++) {
            if (a[i][j] == 1) {
                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                /*if (j == n -1 && i == n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }*/
                fprintf(fpWrite, ";\n");
                check = 1;
            }
        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE
            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);
            fprintf(fpWrite, ";\n");
            /*if (i != n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }*/
        }
    }
    for (i = 0; i < n; i++) {
		fprintf(fpWrite, "      ");
		fprintf(fpWrite, "%d [color=%s, style=filled]", i, color[colorArray[i]]);
		if (i == n-1) {
            fprintf(fpWrite, "\n");
        }
        else {
            fprintf(fpWrite, ";\n");
        }
    }
    fprintf(fpWrite, "}");

}

void colorPlanarGraph (int isColored[], char color[][20], int colorArray[]) {

	int i, j;
	int k = -1;
	for (i = 0; i < n; i++) {
		int child[32];
		int count = 0;
		for (j = i; j < n; j++) {
			if (isNodesConnected(i, j)) {
				child[count++] = j;
			}
		}
		int t;
		for (j = 0; j < count; j++) {
			for (t = j; t < count; t++) {
				if (isNodesConnected(j, t)) {
					if (!isColored[j]) {
						isColored[j] = 1;
						colorArray[j] = ++k % NOC;
					}
					if (!isColored[t]) {
						isColored[t] = 1;
						colorArray[t] = ++k % NOC;
					}
				}
				else {
					++k;
					if (!isColored[j]) {
						isColored[j] = 1;
						colorArray[j] = k % NOC;
					}
					if (!isColored[t]) {
						isColored[t] = 1;
						colorArray[t] = k % NOC;
					}
				}
			}
			
		}
	}
	makePlanarDotFile (color, colorArray);

}

//MAIN BEGINS HERE
int main () {

    char fileName[55];						//storing name of the file
    int checked[32] = {0};					//setting all vertices to be initially unchecked
    int isColored[32] = {0};
    int colorArray[32];
    char color[][20] = {"red", "blue", "green", "magenta", "yellow","darkorange4"};

	printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);					//asking user for input file name
    fpRead = fopen(fileName,"r");

    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
    }
    readAdjacentMatrix ();
    colorPlanarGraph (isColored, color, colorArray);


     return 0;
}
//MAIN ENDS HERE