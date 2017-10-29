#include "graph.h"
#include "queue.h"

int main () {

	int root, dest;
	
	GRAPH *graph = (GRAPH *) malloc (sizeof (GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {

		printf("ERROR... RETURNED 1\n");
		return 1;

	}

	printf("ENTER THE ROOT VERTEX : \n");
	scanf ("%d", &root);

	printf("ENTER THE DESTINATION VERTEX : \n");
	scanf ("%d", &dest);

	dijkstra (graph, root, dest);

	return 0;

}