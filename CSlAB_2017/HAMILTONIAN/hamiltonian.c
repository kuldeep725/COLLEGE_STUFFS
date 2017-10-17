/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 17-10-2017
    * Aim       :
*/
#include "queue.h"
#include "graph.h"

int main () {

    GRAPH *graph;

    printf("Enter filename : \n");
    scanf("%s", (graph->fileName));         	//asking user for input file name

    graph = readAdjacentMatrix(graph);					//reading adjacent matrix
    return 0;

}
