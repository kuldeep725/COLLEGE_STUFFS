/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 17-10-2017
    * Aim       : To find hamiltonian cycle
*/
#include "queue.h"
#include "graph.h"

void findHamiltonianPath (GRAPH *graph) {
    int i, j;
    Queue *queue = createQueue ();
    int visited[32] = {0};
    int start = 0;
    deQueue (queue, start);

    while (!IsQueueEmpty(queue)) {
        int currentNode = deQueue (queue);

        if (currentNode != start) visited[currentNode] = 1;

        for (i = 0; i < graph->n; i++) {
            if (a[currentNode][i] == 1) {
                if (!visited[i]) {

                }
            }
        }
    }

}

int main () {

<<<<<<< HEAD
    GRAPH *graph;

    // printf("Enter filename : \n");
    // scanf("%s", (graph->fileName));         	//asking user for input file name

=======
    GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
    printf("-------------------HAMILTONIAN CYCLE PROBLEM------------------\n");
>>>>>>> 9e5f579f49ba64b408aad1089d30ed42a02be622
    graph = readAdjacentMatrix(graph);					//reading adjacent matrix
    if (graph == NULL) {
        return 1;
    }
    findHamiltonian (graph);                //to find hamiltonian cycle
    free(graph);
    return 0;

}
