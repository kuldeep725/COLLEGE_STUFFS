/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
// NOTE : PROGRAM WORKS FOR ONLY ONE INNER CYCLE PER VERTEX (not more than one so far)

#include "graph.h"
#include "queue.h"

int main () {

	int starting_node;

	GRAPH *graph = (GRAPH *) malloc (sizeof (GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {
		printf("ERROR... RETURNED 1");
		return 1;
	}
	int a_d[32][32] = {0};			//duplicated adjacent matrix with no edges between any vertex
	int i, j;
	int degree[32] = {0};
	
	printf("TELL ME THE STARTING POINT OF THE CYCLE : \n");
	scanf("%d", &starting_node);

	if (IsDegreeEven (graph, degree)) {					//checking if the degree of 
												//all the vertices is even or not
		printf("All vertices have even degree.\n");
		//setIsolatedVertexVisited (graph);
		findEulerianCircuit (graph, starting_node, a_d, degree);

	}
	else {
		printf("No. Eulerian Circuit Doesn't Exist.\n");
	}

	return 0;

}