/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 04-09-2017
    * Aim       : To check if the root and destination node are connected or not, if connected
    			  then find the shortest path between them and write output file showing edges of this path
    			  by red color
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 32
#define RANDOM 5

FILE *fpRead;
FILE *fpWrite;
int a[32][32];
int n;
char s1[32];
int weight[32] = {1};

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
    /*for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%1d", a[i][j]);
        }
        printf("\n");
    }*/

}

//to make dot file from the given adjacency matrix
void makeDotFile () {

    char one[32];
    strcpy(one, s1);
    char str[32];
   	strcpy(str, s1);
    strcat(str, ".dot");
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
//to find out node which is nearest to u and unvisited(in this case, neighbours of u)
int minDistance (int root, int dist[], int checkVisited[]) {

	int min = INT_MAX, minIndex;
	int i;
	//printf("\n");
	for (i = 0; i < n; i++) {
		//printf("dist[%d] = %d, min = %d\n",i, dist[i], min);
		if (checkVisited[i] == 0 && dist[i] < min) {
			min = dist[i];
			minIndex = i;
			//printf("minIndex = %d\n", minIndex);
		}
		//printf("AFTER if : dist[%d] = %d, min = %d\n",i, dist[i], min);
		
	}
	return minIndex;		//returning node nearest to u and unvisited

}
//using recursion to print nodes coming in between root and destination node
void printPath (int parent[], int j) {

	if (parent[j] == -1) return;

	printPath (parent, parent[j]);
	printf("%d ", j);
	a[parent[j]][j] = RANDOM;		//saving RANDOM for coloredDot file
	a[j][parent[j]] = RANDOM;		//saving RANDOM for coloredDot file
	
}

//to print the shortest path
void printSolution (int root, int dest,int dist[], int parent[]) {

	printf("%-9s%-10s%-10s","Vertex", "Distance", "Path");
	printf("\n%d -> %d   %-10d%d ", root, dest, dist[dest] + 1, root);
    printPath(parent, dest);

}

void findShortestPath (int root, int dest) {

	int dist[32];					//to store shortest distance of every vertex from root

	int parent[32];					//to store parent node of every nodes
	int i,j;						//loop counters
	int checkVisited[32] = {0};		//initializing every vertex to be unvisited

	parent[root] = -1;				//since root node doesn't have any parent node
	printf("root = %d && dest = %d\n", root, dest);
	for (i = 0; i < n; i++) {
		dist[i] = INT_MAX - 1;  //setting every distance to be int_max - 1
	}
	dist[root] = 0;				// Distance of root node from itself is always 0
	int flag = 0;				//to check if last numbered node is the destination node
	// Update dist value of the adjacent vertices of the picked vertex.
	for (i = 0; i < n - 1; i++) {

		int u = minDistance (root, dist, checkVisited);		//to find out node which is nearest to u and unvisited(in this case, neighbours of u)
		//printf("\nu = %d\n", u);
		checkVisited[u] = 1;					//marking u to be a visited node

		for (j = 0; j < n; j++) {
			if (!checkVisited[j] && a[u][j] && dist[u] + a[u][j] < dist[j]) {

				parent[j] = u;					//making u to be parent node of j
				dist[j] = dist[u]+a[u][j];		//setting new distance for node j
				/*printf("parent[%d] = %d\n", j, u);
				printf("dist[%d] = %d\n", j, dist[j]);*/

			} 
		}
		if (u == dest) {
			printSolution (root, dest, dist, parent);		//printing shortest path between root and destination
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		printSolution (root, dest, dist, parent);			//printing shortest path between root and destination
	}


}
//to create colored dot file
void makeColoredDotFile () {

    char one[32];
    strcpy(one, s1);
   	char str[32];
   	strcpy(str, s1);
    strcat(str, "Colored.dot");
    fpWrite = fopen(str, "w");                   //creating/ opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    int i,j;
    int check;

    for (i = 0; i < n; i++) {
        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        for (j = i; j < n; j++) {
            if (a[i][j] == 1 || a[i][j] == RANDOM) {
                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                if (a[i][j] == RANDOM) {
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

//MAIN BEGINS HERE
int main () {

    char fileName[55];
    int root;								//Root Node
    int dest;								//Destination Node
    printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);					//asking user for input file name
    fpRead = fopen(fileName,"r");
    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
    }
    readAdjacentMatrix();					//reading adjacent matrix
    makeDotFile();							//creating dot file
    printf("Enter the ROOT node :  \n");
    scanf("%d", &root);						//asking user to input root node
    printf("Enter the DESINATION node : \n");		
    scanf("%d", &dest);						//asking user to input destination node
    int status = isNodesConnected (root, dest);		//checking if root and destination are connected
    if (status == 1) {						//if root and destination are connected
        printf("%d & %d are connected.\n", root, dest);
        findShortestPath (root, dest);		//finding shortest path between root and destination
        printf("\n");
        makeColoredDotFile();				//creating colored dot file
    }
    else {
        printf("%d & %d are not connected.\n", root, dest);			//if root and destination are not connected
    }
    
    return 0;
}
//MAIN ENDS HERE