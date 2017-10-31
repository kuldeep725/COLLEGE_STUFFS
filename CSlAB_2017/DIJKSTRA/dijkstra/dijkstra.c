/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim 		: To find shortest distance between two vertices in 
				  a weighted graph using Dijkstra's Algorithm

	* NOTE 		: ROOT VERTEX -> it is represented by Green Color
				  DESINATION VERTEX -> it is represented by Blue Color
				  PATH -> it is represented by Red Color
				  LABELING -> edges in path are labelled in Navy Blue Color (BIGGER FONT)
				  			  other edges are labelled in Black Color (SMALLER FONT)
				  IMP. NOTE -> read README.txt
*/	

#include "graph.h"
#include "queue.h"

int main () {

	int root, dest;						//root and destination vertices
	int shortest_distance;

	GRAPH *graph = (GRAPH *) malloc (sizeof (GRAPH));
	graph = readAdjacentMatrix (graph);				//reading adjacency matrix

	if (graph == NULL) {

		printf("ERROR... RETURNED 1\n");			//if file is not opening
		return 1;

	}

	printf("ENTER THE ROOT VERTEX : \n");
	scanf ("%d", &root);

	printf("ENTER THE DESTINATION VERTEX : \n");
	scanf ("%d", &dest);

	shortest_distance =  dijkstra (graph, root, dest);					//finding shortest path
	//printf("MIN DISTANCE BETWEEN %d and %d ARE : %d\n", root, dest, shortest_distance);

	return 0;

}