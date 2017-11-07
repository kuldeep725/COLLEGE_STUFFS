#include "graph.h"
int main () {

    GRAPH *graph = (GRAPH *) malloc(sizeof (GRAPH));
    graph = readAdjacentMatrix (graph);

    if (graph == NULL) {

        printf("return %d\n",1);
        return 1;

    }

    findHamiltonianNew (graph);

    return 0;
}
