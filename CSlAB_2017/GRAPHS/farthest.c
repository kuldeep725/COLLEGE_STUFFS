/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 09-10-2017
    * Aim       : to find longest shortest path in a graph
    * NOTE  	: Can be found only on connected graph (noOfComponents = 1)
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
	//printf("root = %d && dest = %d\n", root, dest);
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

int getShortestDistance (int root, int dest) {


	int dist[32];					//to store shortest distance of every vertex from root

	int parent[32];					//to store parent node of every nodes
	int i,j;						//loop counters
	int checkVisited[32] = {0};		//initializing every vertex to be unvisited

	parent[root] = -1;				//since root node doesn't have any parent node
	//printf("root = %d && dest = %d\n", root, dest);
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
			return dist[dest];
		}
	}
	if (flag == 0){
			return dist[dest];
	}


}

int calculateConnectedComponents (int a[][32]){

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

	return counter;
}


int getLongestShortestPath (int b[]) {

	int i, j;
	int maximumDistance = b[0];
	for (i = 0; i < n; i++) {
		if (b[i] > maximumDistance) {
			maximumDistance = b[i];
		}
	}
	return maximumDistance;

}
//to create colored dot file
void makeColoredDotFile () {

    char one[32];
    strcpy(one, s1);
   	char str[32];
   	strcpy(str, s1);
    strcat(str, "ColoredFarthest.dot");
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
                	fprintf(fpWrite, "%s ","[color=red]");			//MAKING THOSE EDGES COLOR RED WHICH ARE IN THE LONGEST SHORTEST PATH
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

void calculateShortestDistanceBetweenAllNodes (int b[]) {

	int i, j;
	int k = 0;

	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			b[k] = getShortestDistance (i,j);					//getting shortest distance between all vertices
			k++;
		}
	}

}

void showLongestShortestPath (int x, int b[]) {

	int i,j;
	int k = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (getShortestDistance(i,j) == x) {			//finding two nodes corresponding to longest shortest distance
				findShortestPath (i,j);						//printing shortest longest path
				return;
			}
		}
	}

}

//MAIN BEGINS HERE
int main () {

	int a[32][32];
	int n;
	char fileName[55];
	int b[64];
	int nearestFarthestNodes[32][32];
	printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);					//asking user for input file name
    fpRead = fopen(fileName,"r");
    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
    }
    readAdjacentMatrix();					//reading adjacent matrix
    int numberOfComponents = calculateConnectedComponents(a);
    printf("numberOfComponents = %d\n", numberOfComponents);
	if (numberOfComponents == 1) {			//minimum longest shortest path can be found only in connected graph
		calculateShortestDistanceBetweenAllNodes (b);
		int longestShortestPath = getLongestShortestPath(b);		//getting longest shortest path in the graph
		printf("longestShortestPath = %d\n", longestShortestPath+1);
		showLongestShortestPath (longestShortestPath, b);			//for showing longest shortest path in the graph with red color
		makeColoredDotFile ();										//making dot file to show the longest shortest path
		printf("\n");
	}
	return 0;
}
//MAIN ENDS HERE
