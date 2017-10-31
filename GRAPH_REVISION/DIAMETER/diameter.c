/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
*/
#include "queue.h"
#include "graph.h"

int main () {

	GRAPH *graph =  (GRAPH *) malloc (sizeof (GRAPH));

	graph = readAdjacentMatrix (graph);

	if (calculateNumberOfConnectedComponents (graph) == 1) {

		printf("DIAMETER EXISTS...\n");
		findDiameter (graph);

	}
	else {
		printf("NUMBER OF COMPONENTS ARE NOT EQUAL TO 1.\n");
		printf("DIAMETER DOESN'T EXIST...\n");
		return 1;
	}

}