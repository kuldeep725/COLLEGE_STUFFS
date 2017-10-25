#include "queue.h"
#include "graph.h"

void printPath (GRAPH *graph, int parent[], int dest, int *dist) {

	*dist += 1;
	if (parent[dest] == -1) return;
	printPath (graph, parent, parent[dest], dist);
	printf("%d ", dest);
	graph->a[parent[dest]][dest] = -5;
	graph->a[dest][parent[dest]] = -5;

}

void printShortestPath (GRAPH *graph, int root, int dest, int parent[], int *dist) {

	// printf("%-9s%-10s%-10s","Vertex", "Distance", "Path");
	// printf("\n%d -> %d   %-10d%d ", root, dest, , root);
	printf("PATH (%d -> %d) :  ", root, dest);
	printf("%d ", root);
    printPath(graph, parent, dest, dist);
    printf("\nDistance (%d -> %d) : %d\n", root, dest, *dist);

}

void findShortestPath (GRAPH *graph, int root, int dest) {

	int visited[32] = {0};
	int parent[32];
	int v;
	int dist = 0;

	Queue *queue = createQueue ();
	enQueue (queue, root);
	visited[root] = 1;
	parent[root] = -1;

	while (!IsQueueEmpty(queue)) {

		int currentNode = deQueue (queue);
		int flag = 0;

		for (v = 0; v < graph->n; v++) {

			if (!visited[v] && graph->a[currentNode][v] != 0) {

				parent[v] = currentNode;		//currentNode is the parent of vertex v
				if (v == dest) {
					flag = 1;
					break;
				}
				enQueue (queue, v);
				visited[v] = 1;

			}
		}
		if (flag) break;

	}
	printShortestPath (graph, root, dest, parent, &dist);

}

int main () {

	GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) return 1;

	int root, dest;
	printf("ENTER ROOT AND DESTINATION : \n");
	scanf("%d%d", &root, &dest);

	if (BFS (graph, root, dest)) {

		printf("%d and %d are connected\n", root, dest);
		findShortestPath (graph, root, dest);

	}

	else {
		printf("%d and %d are not connected\n", root, dest);
	}

	return 0;

}