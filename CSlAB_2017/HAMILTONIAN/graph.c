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

    FILE fpRead = fopen(fileName,"r");
    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return 1;							//returning 1 since program didn't work
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
