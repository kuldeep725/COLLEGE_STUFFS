#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include "queue.h"
#include "graph.h"

//to search if root and dest are connected or not
int areNodesConnected (GRAPH *graph, int root, int dest) {

    int checked [32] = {0};     //making all to be unchecked (0)
    Queue *queue = createQueue ();             //creating queue

    checked[root] = 1;          //making root as visited
    enQueue (queue, root);
    int i;
    while (!IsQueueEmpty(queue)) {
        int currentNode = deQueue(queue);                           //finding current node
        if (currentNode == dest) {
            return 1;                           //return 1 if the dest is found to be connected to root
        }
        //printf("currentNode = %d\n", currentNode);
        for (i = 0; i < graph->n; i++) {
            //printf("checked[%d] = %d\n", i, checked[i]);
            if (graph->a[currentNode][i] == 1) {
                if (checked[i] != 1) {
                    checked[i] = 1;         //marking node as visited
                    enQueue(queue, i);
                }
            }

        }
    }
    return 0;
}

//to read the file containing adjacency matrix
GRAPH * readAdjacentMatrix (GRAPH *graph) {

    graph = (GRAPH *) malloc(sizeof(GRAPH));
    printf("ENTER THE NAME OF THE FILE : \n");
    char name[32];
    scanf("%[^\n]s", name);
    FILE *fpRead = fopen(name,"r");
    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return NULL;							//returning 1 since program didn't work
    }
    char s1[32];
    char s2[32];            //to store input string
    fscanf(fpRead, " %[^\n]s",s1);
    strcpy (graph->fileName, s1);
    fscanf(fpRead, " %[^\n]s",s2);
    fscanf(fpRead, "%d", &graph->n);       //to read number of rows/columns in the adjacency matrix
    int i, j;               //loop variables
    for (i = 0; i < graph->n; i++) {
        for (j = 0; j < graph->n; j++) {
            fscanf(fpRead, "%1d", &(graph->a[i][j]));        //taking input as n*n adjacency matrix from the input file
        }
    }
    return graph;

}

/* A utility function to print solution */
void printSolution(GRAPH *graph, int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < graph->n; i++)
        printf(" %d ", path[i]);
 
    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}

int isSafe (int v, GRAPH *graph, int path[], int pos) {
    if (graph->a[path[pos-1]][v] == 0) {
        return 0;
    }
    int i;
    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
 
    return 1;
}

int hamCycleUtil (GRAPH *graph, int path[], int pos) {

    if (pos == graph->n) {
        if (graph->a[path[pos-1]][path[0]]){
            return 1;
        }
        else {
            return 0;
        }
    }
    int v;
    for (v = 1; v < graph->n; v++) {
        if (isSafe (v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil (graph, path, pos + 1)) {
                return 1;
            }
            path[v] = -1;
        }
    }
    return 0;
}

void makeDotFileForHamiltonian (GRAPH *graph, int path[]) {

    char one[32];
    strcpy(one, graph->fileName);
    char str[32];
    strcpy(str, one);
    strcat(str, "Hamiltonian.dot");
    int n = graph->n;
    FILE *fpWrite = fopen(str, "w");                   //creating/ opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    int i,j, k = 0;
    int check;
   // printf("path[%d] = %d\n", n, path[n]);

    for (i = 0; i < n; i++) {
        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        k = 0;
        for (; k < n; k++) {
            if(path[k]==i) break;
        }
        for (j = i; j < n; j++) {
            if (graph->a[i][j] == 1) {
                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                if (path[k+1] == j) {
                    fprintf(fpWrite, "[color = %s] ", "red");
                }
                if (k != 0 && path[k-1] == j) {
                    fprintf(fpWrite, "[color = %s] ", "red");
                }
                if (i == 0 && path[n-1] == j) {
                    fprintf(fpWrite, "[color = %s] ", "red");
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
int hamCycle(GRAPH *graph)
{
    int path[graph->n];
    for (int i = 0; i < graph->n; i++)
        path[i] = -1;
    
    /* Let us put vertex 0 as the first vertex in the path. If there is
       a Hamiltonian Cycle, then the path can be started from any point
       of the cycle as the graph is undirected */
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == 0 )
    {
        printf("\nSolution does not exist");
        return 0;
    }
    printSolution(graph, path);
    makeDotFileForHamiltonian (graph, path);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");
    return 1;
}

void findHamiltonian (GRAPH *graph) {

    hamCycle (graph);


}