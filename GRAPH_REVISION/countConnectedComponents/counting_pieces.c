#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "graph.h"


int main () {

	GRAPH *graph = (GRAPH  *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	int noOfConnectedComponents = calculateNumberOfConnectedComponents (graph);
	
	printf("THE NUMBER OF CONNECTED COMPONENTS ARE : %d\n", noOfConnectedComponents);

	return 0;

}