/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 09-10-2017
    * Aim       : To count total number of different connected components in the graph
    * NOTE  	: Coloring can be done for maximum 5 different connected graphs
*/
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>

#define MAX 32
#define RANDOM 5

FILE *fpRead;
FILE *fpWrite;
int a[32][32];
int n;
char s1[32];
int previous[32];

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
	//checking if the front is null or not
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

void BFS (int previous[]) {
	int checked [32] = {0};     //making all to be unchecked (0)
    createQueue ();             //creating queue
    checked[0] = 0;
    int i,j;
    int t = 0;
    for (j = 0; j <  n; j++) {

    	if (checked[j] != 1) {
    		/*if (queueIsEmpty) {
    			printf("queueIsEmpty\n");
    		}*/
    		enQueue(j);
    		//printf("j = %d\n", j);
	    	while (!queueIsEmpty()) {
		        int currentNode = deQueue ();                           //finding current node
		        if (t == 0) {
		        	currentNode = j;
		        }
		        t++;
		        //printf("currentNode = %d\n", currentNode);
		        for (i = 0; i < n; i++) {
		            //printf("checked[%d] = %d\n", i, checked[i]);
		            if (a[currentNode][i] == 1) {
		                if (checked[i] != 1) {
		                    checked[i] = 1;         //marking node as visited
		                    enQueue(i);
		                    previous[i] = currentNode;
		                }
		            }

		        }
	    	}
    	}
    	
    }
    
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

void makeDotFileWithDifferentComponents (int component[32][32], int counter, int k[], int lastArray[][32]) {

	char one[32];
    strcpy(one, s1);
    char str[32];
   	strcpy(str, s1);
    strcat(str, "Components.dot");
    fpWrite = fopen(str, "w");                   //creating/ opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    int i,j;
    int check;
    int u,v;
    int last = 0;

    for (i = 0; i < n; i++) {
        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        for (j = i; j < n; j++) {
            if (a[i][j] == 1) {
                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                for (u = 0; u < counter; u++) {
                	for(v = 0; v < k[u]; v++) {
                		/*printf("j = %d and component[%d][%d] = %d\n", j,u,v,component[u][v]);
                		printf("lastArray[%d][%d] = %d\n", u,v, lastArray[u][v]);*/
                		if (lastArray[u][v] == j) {
                			switch (u) {
                			case 0 :
                				fprintf(fpWrite, "%s ","[color=red]");
                				//printf("WE ARE IN 0\n");
                				break;
                			case 1 :
                				fprintf(fpWrite, "%s ","[color=green]");
                				//printf("WE ARE IN 1\n");
                				break;
                			case 2 :
                				fprintf(fpWrite, "%s ","[color=blue]");
                				//printf("WE ARE IN 2\n");
                				break;
                			case 3 :
                				fprintf(fpWrite, "%s ","[color=magneta]");
                				//printf("WE ARE IN 3\n");
                				break;
                			case 4 :
                				fprintf(fpWrite, "%s ","[color=cyan]");
                				//printf("WE ARE IN 4\n");
                				break;
                			default :
                				fprintf(fpWrite, "%s ","[color=black]");
                				//printf("WE ARE IN DEFAULT\n");
                				break;
                		}
                		break;
                		
                		}
                	}
                }

               
                if (j == n -1 && i == n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }
        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE
            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }
        }
    }
    fprintf(fpWrite, "}");

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
	/*printf("counter = %d\n", counter);
	
	printf("FOR EDUCATIONAL PURPOSE : \n");
	for (i = 0; i < counter; i++) {
		for (j = 0; j < k[i]; j++) {
			printf("component[%d][%d] = %d\n", i, j, component[i][j]);
			printf("lastArray[%d][%d] = %d\n", i, j, lastArray[i][j]);
		}
		printf("\n");
	}*/

	makeDotFileWithDifferentComponents (component, counter, k, lastArray);

	return counter;
}

void makingDotAgain (int previous[]) {

	 char one[32];
    strcpy(one, s1);
    char str[32];
   	strcpy(str, s1);
    strcat(str, "Again.dot");
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
                if (previous[i] == j || previous[j] == i) {
                	fprintf(fpWrite, "%s ","[color=red]");
                }
                if (j == n -1 && i == n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }
        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE
            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }
        }
    }
    fprintf(fpWrite, "}");

}

int main () {
	
	int n;
	char fileName[55];
	int previous[32];
	
	printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);					//asking user for input file name
    fpRead = fopen(fileName,"r");
    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
    }
    readAdjacentMatrix();					//reading adjacent matrix
    int numberOfComponents = calculateConnectedComponents();
    printf("numberOfComponents = %d\n", numberOfComponents);
    BFS (previous);
    makingDotAgain (previous);
	return 0;
}