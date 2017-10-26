#include "queue.h"
#include "graph.h"

int main () {

	GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) return 1;

	int root, dest;
	printf("ENTER ROOT AND DESTINATION : \n");
	scanf("%d%d", &root, &dest);

	if (BFS (graph, root, dest)) {

		printf("%d and %d are connected\n", root, dest);
		findShortestPath (graph, root, dest);

	}

	else {
		printf("%d and %d are not connected\n", root, dest);
	}

	return 0;

}