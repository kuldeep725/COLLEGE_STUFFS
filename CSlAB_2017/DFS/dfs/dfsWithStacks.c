/*

    * Name      : Kuldeep Singh Bhandaridfs
    * Roll No.  : 111601009

*/
#include "stack.h"
#include "graph.h"

int main () {

	int root;
	int choice;

	GRAPH *graph = (GRAPH *) malloc(sizeof(GRAPH));
	graph = readAdjacentMatrix (graph);

	if (graph == NULL) {

		printf("ERROR... RETURNED 1\n");			//if file is not opening
		return 1;

	}

	printf("ENTER THE STARTING VERTEX : \n");
	scanf ("%d", &root);

	do {
			printf("-----------MAIN MENU-----------\n\n" );
			printf("1. DFS USING STACKS \n");
			printf("2. DFS USING RECURSION\n");
			printf("3. EXIT\n");
			printf("ENTER CHOICE : \n");
			scanf ("%d", &choice);

			switch (choice) {

				case 1 : dfsUsingStack (graph, root);
						 break;

				case 2 : dfsUsingRecursion (graph, root);
						 break;
				case 3 :
						 printf("EXITING...\n");
						 break;

				default : printf ("WRONG CHOICE !!");
					 	 break;


			}
	} while (choice != 3);

	return 0;

}
