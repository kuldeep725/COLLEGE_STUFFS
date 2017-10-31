/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/

#include "graph.h"
#include "queue.h"

int main () {

	GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {

		printf("ERROR... RETURNED 1");
		return 1;

	}

	coloringWithSixColors (graph);
	return 0;

}