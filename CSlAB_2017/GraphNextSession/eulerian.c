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

//to check if any edges left between any vertices
int haveEdgesLeft () {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                return 1;
            }
            //printf("%d ", a[i][j]);
        }
        //printf("\n");
    }
    return 0;
}

//to display eulerian path
void displayEulerianPath (path *start) {

    path *p = start;
    printf("START --> ");
    do {

        printf("%d --> ", p->vertex);
        p = p->next;
    } while (p != start);
    printf("END\n");
    printf("\n");

}

/*int oneMoreThanOther (int p, int q, int degree[]) {

	int degree1 = 0, degree2 = 0;
	int i,j;
	for (i = 0; i < n; i++) {
		if (a[p][i] == 1) {
			degree1 += degree[i];
		}
		if (a[q][i] == 1) {
			degree2 += degree[i];
		}
	}
	printf("degree1 = %d\n", degree1);
	printf("degree2 = %d\n", degree2);
	printf("degree1 > degree2 = %d\n", degree1 > degree2);
	return (degree1 > degree2);

}*/


/*int max (int connectedArray[], int m, int degree[]) {

	int maxIndex = connectedArray[0];
	int i;
	for (i = 0; i < m; i++) {
		if (degree[connectedArray[i]] > degree[maxIndex]) {
			maxIndex = connectedArray[i];
		}
		else if (degree[connectedArray[i]] == degree[maxIndex]) {
			printf("Maximum off : (connectedArray[%d], connectedArray[%d])\n", connectedArray[i], connectedArray[maxIndex]);
			if (oneMoreThanOther(connectedArray[i], connectedArray[maxIndex], degree)){
				
				maxIndex = connectedArray[i];
			}
		}
	}
	printf("maxIndex = %d\n", maxIndex);
	return maxIndex;

}*/

void findEulerianCircuit (path *start, int checked[], int degree[]) {

    checked[start->vertex] = 1;
    path *p = start;
    path *temp = start;
    front = NULL;
    rear = NULL;
    //printf("start->vertex = %d\n", start->vertex);
    int root = start->vertex;
    enQueue (root);
    int i;
<<<<<<< HEAD
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
=======
    //int j = 0;
    /*int count;
    int connectedArray[100];*/
    
    while(degree[root] != 0) {
        int currentNode = deQueue ();
        int flag = 0;
        int k = 0;
       // printf("currentNode = %d\n", currentNode);
        //printf("degree[%d] = %d\n", root, degree[root]);
        for (i = 0; i < n; i++) {
            //count = 0;
            if (a[currentNode][i] == 1) {
                    
                    //printf("a[%d][%d] = %d\n", currentNode,i, a[currentNode][i]);
                   // printf("degree[%d] = %d, degree[%d] = %d\n", currentNode, degree[currentNode], i, degree[i]);
                    if (i == root) {
                    	if (degree[currentNode] == 1) {
                    		enQueue(i);
                    		p = (path *) malloc(sizeof(path));
	                        p->vertex = i;
	                        temp->next = p;
	                        temp = p;
                    		a[currentNode][i] = 0;
                    		a[i][currentNode] = 0;
                    		degree[currentNode]--;
                   			degree[i]--;
                   			flag = 1;
                   			//haveEdgesLeft();
                   			break;
                   			
                    	}
                    	
>>>>>>> e3a80b2f9ca12b23a329f4c5899de1f475f8fe79
                    }
                    else {
                    	enQueue(i);
			        	p = (path *) malloc(sizeof(path));
			            p->vertex = i;
			            temp->next = p;
			            temp = p;
			        	a[currentNode][i] = 0;
			    		a[i][currentNode] = 0;
			    		degree[currentNode]--;
			   			degree[i]--;
			   			break;
                    	//connectedArray[k++] = i; 
                    	//printf("connectedArray[%d] = %d\n", k-1,connectedArray[k-1]);
                    }
                   
        	}
            
        }

	}
	if (!haveEdgesLeft ()) {
	        temp->next = start;
	        displayEulerianPath (start);
	}
}

void freeNode (path *start) {

    /*printf("start->vertex = %d\n", start->vertex);
    printf("start->next->vertex = %d\n", start->next->vertex);*/
    path *p = start->next;
    path *temp;

    do {

        temp = p;
        p = p->next;
//        printf("TEMP->vertex = %d\n", temp->vertex);
        temp->next = NULL;
        free(temp);

    } while (p != start);
    //printf("START->vertex = %d\n", start->vertex);
    free(start);

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
        //printf("checked [%d]= %d\n", i, checked[i]);
    }
}

//setting degrees of all vertices
void setDegrees (int degree[]) {

	int i, j;
	for (i = 0; i < n; i++) {
		degree[i] = 0;
		for (j = 0; j < n; j++) {
			degree[i] += a[i][j];
		}
		//printf("degree[%d] = %d\n", i, degree[i]);
	}

}

//MAIN BEGINS HERE
int main () {

    int startingNode;						//starting Node for eulerian path
    char fileName[55];						//storing name of the file
    int checked[32] = {0};					//setting all vertices to be initially unchecked
    int degree[32];							//to store degree of all vertices

	printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);					//asking user for input file name
    fpRead = fopen(fileName,"r");

    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
    }

    printf("Enter the starting Node : \n");
    scanf("%d", &startingNode);
    path *start = (path *) malloc(sizeof(path));
    start->vertex = startingNode;
    start->next = NULL;

    readAdjacentMatrix();					//reading adjacent matrix
    if (isDegreeEven()) {					//if all degrees are even
        printf("Degrees are Even\n");
        markAllZeroDegreeVertexAsVisited (checked);
        setDegrees(degree);
        if (calculateConnectedComponents() == 1) {
            printf("EULERIAN PATH EXISTS\n");
            findEulerianCircuit (start, checked, degree);		//printing eulerian path
        }

    }
    else {
        printf("%s\n", "Degrees are not even. Not a eulerian graph.");
    }
    if (start != NULL) {freeNode(start);}
    return 0;
}
//MAIN ENDS HERE