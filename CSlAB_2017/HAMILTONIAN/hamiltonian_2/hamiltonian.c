/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 17-10-2017
    * Aim       : To find hamiltonian cycle
*/
#include "queue.h"
#include "graph.h"

int main () {

    GRAPH *graph;
    printf("-------------------HAMILTONIAN CYCLE PROBLEM------------------\n");
    graph = readAdjacentMatrix(graph);					//reading adjacent matrix
    if (graph == NULL) {
        return 1;
    }
    findHamiltonian (graph);                //to find hamiltonian cycle
    free(graph);
    return 0;

}
