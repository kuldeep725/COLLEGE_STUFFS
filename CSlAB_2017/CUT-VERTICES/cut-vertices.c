/*

    * Name      : Kuldeep Singh Bhandaridfs
    * Roll No.  : 111601009

*/
#include "stack.h"
#include "graph.h"

int main () {

	GRAPH *graph = (GRAPH *) malloc (sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {

		printf("ERROR... RETURNED 1\n");			//if file is not opening
		return 1;

	}

	findCutVertices (graph);
	
	return 0;

}