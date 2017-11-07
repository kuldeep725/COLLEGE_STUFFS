/*

    * Name      : Kuldeep Singh Bhandaridfs
    * Roll No.  : 111601009

*/
#include "stack.h"
#include "graph.h"

int main () {

	int root;

	GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {

		printf("ERROR... RETURNED 1\n");			//if file is not opening
		return 1;

	}

	printf("ENTER THE STARTING VERTEX : \n");
	scanf ("%d", &root);

	dfsUsingRecursion (graph, root);
	return 0;

}
