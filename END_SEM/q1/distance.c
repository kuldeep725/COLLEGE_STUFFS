/*

    * Name      : Kuldeep Singh Bhandaridfs
    * Roll No.  : 111601009
	  NOTE : "stack smashing detected" may be printed but output will be correct. 
	  		 In case, only "stack smashing detected" is printed, it means no of connected components 
	  		 is not 1
*/
#include "graph.h"

int main () {

	GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {

		printf("RETURNING 1\n");
		return 1;

	}

	findDistance (graph);				//TO FIND DISTANCE BETWEEN ALL VERTICES

	return 0;

}