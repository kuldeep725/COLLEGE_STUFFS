/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include "queue.h"
#include "graph.h"
#include "stack.h"

int BFS (GRAPH *graph, int root, int dest) {

    int visited[32] = {0};          //making all to be unchecked (0)
    int i;
    int level[32];

    Queue *queue = createQueue ();      //creating queue

    visited[root] = 1;              //making root as visited
    enQueue (queue, root);
    level[root] = 0;

    while (!isQueueEmpty(queue)) {

        int currentNode = deQueue (queue);          //finding current node

        if (currentNode == dest) {
            //printf("dist = %d\n", level[dest]);
            return level[dest];                 //return level of the destination node
                                                //if the dest is found to be connected to root
        }

        for (i = 0; i < graph->n; i++) {

            if (!visited[i] && graph->a[currentNode][i] != 0) {

                enQueue (queue, i);
                visited[i] = 1;         //marking node as visited
                level[i] = level[currentNode] + 1;

            }

        }

    }

    return 0;

}

//to make dot file from the given adjacency matrix
void makeDotFile (GRAPH *graph) {

    int i,j;
    int check;
    char one[32];
    char str[32];

    int n = graph->n;
    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form
                                                       //of the adjacency matrix

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, ".dot");

    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT

        for (j = i; j < graph->n; j++) {

            if (graph->a[i][j] != 0) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }

        }

        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }

        }
    }

    fprintf(fpWrite, "}");
    fclose(fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}
//to read the file containing adjacency matrix
GRAPH * readAdjacentMatrix (GRAPH *graph) {

    char s1[32];
    char s2[32];            //to store input string
    char name[32];

    if (graph == NULL) graph = (GRAPH *) malloc(sizeof(GRAPH));

    printf("ENTER THE NAME OF THE FILE : \n");
    scanf("%s", name);

    FILE *fpRead = fopen(name,"r");

    if (fpRead == 0) {

        printf("ERROR IN FILE OPENING.\n");			//error in file opening
        return NULL;							//returning null since program didn't work

    }

    fscanf(fpRead, " %[^\n]s",s1);

    strcpy (graph->fileName, s1);

    fscanf(fpRead, " %[^\n]s",s2);
    fscanf(fpRead, "%d", &graph->n);       //to read number of rows/columns in the adjacency matrix

    int i, j;               //loop variables

    for (i = 0; i < graph->n; i++)
        for (j = 0; j < graph->n; j++)
            fscanf(fpRead, "%1d", &(graph->a[i][j]));        //taking input as n*n adjacency matrix from the input file


    fclose(fpRead);
    return graph;

}

// //hamiltonian program function starts here
//
// /* A utility function to print solution */
// void printSolution(GRAPH *graph, int path[])
// {
//     printf ("Solution Exists:"
//             " Following is one Hamiltonian Cycle \n");
//     for (int i = 0; i < graph->n; i++)
//         printf(" %d ", path[i]);
//
//     // Print the first vertex again to show the complete cycle
//     printf(" %d ", path[0]);
//     printf("\n");
// }
//
// /* A utility function to check if the vertex v can be added at
//    index 'pos' in the Hamiltonian Cycle constructed so far (stored
//    in 'path[]') */
// int isSafe (int v, GRAPH *graph, int path[], int pos) {
//     /* Check if this vertex is an adjacent vertex of the previously
//        added vertex. */
//     if (graph->a[path[pos-1]][v] == 0) {
//         return 0;
//     }
//     int i;
//     /* Check if the vertex has already been included */
//     for (i = 0; i < pos; i++)
//         if (path[i] == v)
//             return 0;
//
//     return 1;
// }
// /* A recursive utility function to solve hamiltonian cycle problem */
// int hamCycleUtil (GRAPH *graph, int path[], int pos) {
// /* base case: If all vertices are included in Hamiltonian Cycle */
//     if (pos == graph->n) {
//         // And if there is an edge from the last included vertex to the
//         // first vertex
//         if (graph->a[path[pos-1]][path[0]]){
//             return 1;
//         }
//         else {
//             return 0;
//         }
//     }
//     int v;
//     // Try different vertices as a next candidate in Hamiltonian Cycle.
//     // We don't try for 0 as we included 0 as starting point in in hamCycle()
//     for (v = 1; v < graph->n; v++) {
//         /* Check if this vertex can be added to Hamiltonian Cycle */
//         if (isSafe (v, graph, path, pos)) {
//             path[pos] = v;
//             /* recur to construct rest of the path */
//             if (hamCycleUtil (graph, path, pos + 1)) {
//                 return 1;
//             }
//             /* If adding vertex v doesn't lead to a solution,
//                then remove it */
//             path[v] = -1;
//         }
//     }
//     /* If no vertex can be added to Hamiltonian Cycle constructed so far,
//        then return 0 */
//     return 0;
// }
//
// //to create dot file to show hamiltonian path in red color
// void makeDotFileForHamiltonian (GRAPH *graph, int path[]) {
//
//     char one[32];
//     strcpy(one, graph->fileName);
//     char str[32];
//     strcpy(str, one);
//     strcat(str, "Hamiltonian.dot");
//     int n = graph->n;
//     FILE *fpWrite = fopen(str, "w");                   //creating/ opening a file to write dot form of the adjacency matrix
//     //NOW WE START WRITING DATA IN THE FILE
//
//     fprintf(fpWrite, "graph %s {\n", one);
//
//     int i,j, k = 0;
//     int check;
//    // printf("path[%d] = %d\n", n, path[n]);
//
//     for (i = 0; i < n; i++) {
//         check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
//         k = 0;
//         //finding location of vertex i in the array path[]
//         for (; k < n; k++) {
//             if(path[k]==i) break;
//         }
//         for (j = i; j < n; j++) {
//             if (graph->a[i][j] != 0) {
//                 fprintf(fpWrite, "      ");
//                 fprintf(fpWrite, "%d -- %d ", i, j);
//                 if (path[k+1] == j) {
//                     fprintf(fpWrite, "[color = %s] ", "red");
//                 }
//                 if (k != 0 && path[k-1] == j) {
//                     fprintf(fpWrite, "[color = %s] ", "red");
//                 }
//                 if (i == 0 && path[n-1] == j) {
//                     fprintf(fpWrite, "[color = %s] ", "red");
//                 }
//                 if (j == n -1 && i == n-1) {
//                     fprintf(fpWrite, "\n");
//                 }
//                 else {
//                     fprintf(fpWrite, ";\n");
//                 }
//                 check = 1;
//             }
//         }
//         if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE
//             fprintf(fpWrite, "      ");
//             fprintf(fpWrite, "%d ", i);
//
//             if (i != n -1) {
//                 fprintf(fpWrite, ";\n");
//             }
//             else {
//                 fprintf(fpWrite, "\n");
//             }
//         }
//     }
//     fprintf(fpWrite, "}");
//     printf("DOT FILE CREATED SUCCESSFULLY...\n");
// }
//
// /* This function solves the Hamiltonian Cycle problem using Backtracking*/
// int hamCycle(GRAPH *graph)
// {
//     int path[graph->n];
//     for (int i = 0; i < graph->n; i++)
//         path[i] = -1;
//
//     /* Let us put vertex 0 as the first vertex in the path. If there is
//        a Hamiltonian Cycle, then the path can be started from any point
//        of the cycle as the graph is undirected */
//     path[0] = 0;
//     if ( hamCycleUtil(graph, path, 1) == 0 )
//     {
//         printf("\nSolution does not exist");
//         return 0;
//     }
//     printSolution(graph, path);
//     makeDotFileForHamiltonian (graph, path);
//     printf("DOT FILE CREATED SUCCESSFULLY...\n");
//     return 1;
// }
//
// void findHamiltonian (GRAPH *graph) {
//
//     hamCycle (graph);
//
//
// }

// pathfinder program function starts here

void printPath (GRAPH *graph, int parent[], int dest) {


    if (parent[dest] == -1) return;

    printPath (graph, parent, parent[dest]);
    printf("%d ", dest);
    // printf("dist[%d] = %d\n",dest, dist[dest]);
    graph->a[parent[dest]][dest] = -5;
    graph->a[dest][parent[dest]] = -5;

}

void printShortestPath (GRAPH *graph, int root, int dest, int parent[], int dist) {

    // printf("%-9s%-10s%-10s","Vertex", "Distance", "Path");
    // printf("\n%d -> %d   %-10d%d ", root, dest, , root);
    // *dist = 0;
    printf("PATH (%d -> %d) :  ", root, dest);
    printf("%d ", root);
    printPath(graph, parent, dest);
    printf("\nDistance (%d -> %d) : %d\n", root, dest, dist);

}


void makeDotFileForPathFinder (GRAPH *graph) {

    char one[32];
    char str[32];
    int n = graph->n;
    int i,j;
    int check;

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, "pathFinder.dot");

    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT

        for (j = i; j < graph->n; j++) {

            if (graph->a[i][j] != 0) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);

                if (graph->a[i][j] == -5) {
                    fprintf(fpWrite, "[color=red] ");
                }

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }

                else {
                    fprintf(fpWrite, ";\n");
                }

                check = 1;

            }

        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }

            else {
                fprintf(fpWrite, "\n");
            }

        }

    }

    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}

int findShortestPath (GRAPH *graph, int root, int dest) {

    int visited[32] = {0};
    int parent[32];
    int v;
    int dist = 0;
    int max = 0;
    int level[32];
    int i;

    Queue *queue = createQueue ();
    enQueue (queue, root);
    visited[root] = 1;
    parent[root] = -1;
    level[root] = 0;

    while (!isQueueEmpty(queue)) {

        int currentNode = deQueue (queue);
        int flag = 0;

        for (v = 0; v < graph->n; v++) {

            if (!visited[v] && graph->a[currentNode][v] != 0) {

                parent[v] = currentNode;        //currentNode is the parent of vertex v
                if (v == dest) {
                    flag = 1;
                    break;
                } //if destination vertex is found

                enQueue (queue, v);
                visited[v] = 1;                 //marking vertex v to be visited
                level[v] = level[currentNode] + 1;

            }
        }
        if (flag) break;

    }

    printShortestPath (graph, root, dest, parent, level[dest]);            //to print the shortest path
    makeDotFileForPathFinder (graph);
    return level[dest];

}

// shortRed program functions here

void makeDotFileForShortRed (GRAPH *graph) {

    char one[32];
    strcpy(one, graph->fileName);
    char str[32];
    strcpy(str, one);
    strcat(str, "shortRed.dot");
    int n = graph->n;
    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    int i,j;
    int check;

    for (i = 0; i < graph->n; i++) {
        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        for (j = i; j < graph->n; j++) {
            if (graph->a[i][j] != 0) {
                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                if (graph->a[i][j] == -5 || graph->a[j][i] == -5) {
                    fprintf(fpWrite, "%s ","[style=dotted, color=red]");
                }
                else if (graph->a[i][j] == 1 || graph->a[j][i] == 1) {
                    fprintf(fpWrite, "%s ","[color=red]");
                }
                else if (graph->a[i][j] == 2 || graph->a[j][i] == 2) {
                    fprintf(fpWrite, "%s ","[color=blue]");
                }
                else if (graph->a[i][j] == 3 || graph->a[j][i] == 3) {
                    fprintf(fpWrite, "%s ","[color=green]");
                }
                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }
        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE
            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }
        }
    }
    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

 }

int countRedEdges (GRAPH *graph, int currentNode, int parent[]) {

    if (parent[currentNode] == -1) return 0;

    int count = countRedEdges (graph, parent[currentNode], parent);

    if (graph->a[parent[currentNode]][currentNode] == 1) count++;
    return count;

}

void findShortestPathWithRed (GRAPH *graph, int root, int dest) {

    int visited[32] = {0};
    int parent[32];
    int v;
    int dist = 0;
    int level[32];
    int red[32];
    int pre_dest = -5;              //node just before destination node
    int minDistance = 0;
    int noOfRed = 0;

    Queue *queue = createQueue ();
    enQueue (queue, root);
    visited[root] = 1;
    parent[root] = -1;
    level[root] = 0;

    while (!isQueueEmpty(queue)) {

        int currentNode = deQueue (queue);
        //printf("\ncurrentNode = %d\n", currentNode);
        if (currentNode == dest) break;


        for (v = 0; v < graph->n; v++) {

            if (!visited[v] && graph->a[currentNode][v] != 0) {

                if (v != dest) {
                    parent[v] = currentNode;        //currentNode is the parent of vertex v
                }

                if (v == dest) {

                    //printf("currentNode for dest : %d\n", currentNode);
                    //printf("minDistance = %d\n", level[currentNode] + 1);
                    minDistance = level[currentNode];
                    if (pre_dest == -5) {
                        //printf("pre_dest previously = -5\n");
                        pre_dest = currentNode;
                        //printf("pre_dest = %d\n", pre_dest);
                        noOfRed = countRedEdges (graph, currentNode,parent);
                        //printf("noOfRed = %d\n", noOfRed);
                        parent[v] = currentNode;        //currentNode is the parent of vertex v
                        if (graph->a[currentNode][v] == 1) noOfRed++;
                        //printf("FINAL noOfRed = %d\n", noOfRed);
                    }
                    else if (noOfRed == countRedEdges (graph, currentNode, parent)) {
                        if (graph->a[currentNode][v] == 1) {
                            pre_dest = currentNode;
                            parent[v] = currentNode;        //currentNode is the parent of vertex v
                            noOfRed++;
                            // printf("pre_dest = %d\n", pre_dest);
                            // printf("FINAL noOfRed = %d\n", noOfRed);
                        }
                    }
                    continue;

                }
                enQueue (queue, v);
                level[v] = level[currentNode] + 1;
                visited[v] = 1;

            }
        }

    }
    printf("noOfRed = %d\n", noOfRed);
    printf("minDistance = %d\n", minDistance);
    printShortestPath (graph, root, dest, parent, level[dest]);
    makeDotFileForShortRed (graph);

}

//  counting_pieces starts here

int haveVerticesLeft (GRAPH *graph, int visited[]) {

    int i;

    for (i = 0; i < graph->n; i++) {

        if (visited[i] == 0) {
            return i;
        }

    }

    return -1;

}

void makeDotFileForCountingPieces (GRAPH *graph, int edgeColor[]) {

    char color[][15] = {"red", "blue", "green", "magenta", "cyan", "yellow"};
    int i,j;
    int check;
    char one[32];
    char str[32];

    int n = graph->n;

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, "counting_pieces.dot");

    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form of the adjacency matrix

    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        for (j = i; j < graph->n; j++) {

            if (graph->a[i][j] == 1) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                fprintf(fpWrite, " [color = %s] ", color[edgeColor[i]]);

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }
        }

        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }
        }
    }
    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}

//to calculate Number of Connected Components
int calculateNumberOfConnectedComponents (GRAPH *graph) {

    int visited[32] = {0};          //making all to be unchecked (0)
    Queue *queue = createQueue ();      //creating queue

    visited[0] = 1;              //making root as visited
    enQueue (queue, 0);
    int v;
    int noOfConnectedComponents = 1;

    int edgeColor[32];


    while (!isQueueEmpty(queue)) {

        int currentNode = deQueue (queue);          //finding current node
        visited[currentNode] = 1;

        for (v = 0; v < graph->n; v++) {

            if (!visited[v] && graph->a[currentNode][v] != 0) {
                enQueue (queue, v);
                visited[v] = 1;         //marking node as visited
            }

        }

        edgeColor [currentNode] = noOfConnectedComponents - 1;
       // printf("currentNode = %d\n", currentNode);
        //printf("isQueueEmpty() = %d\n", isQueueEmpty (queue));
        if (isQueueEmpty (queue)) {

            //printf("haveVerticesLeft() = %d\n", haveVerticesLeft (graph, visited));
            if (haveVerticesLeft (graph, visited) != -1) {

                //printf("Vertex %d\n", haveVerticesLeft(graph, visited));
                enQueue (queue, haveVerticesLeft(graph, visited));
                noOfConnectedComponents++;

            }

        }

    }
    /*for (v = 0; v < graph-> n; v++) {

        printf("edgeColor[%d] = %d\n", v, edgeColor[v]);

    }*/

    //makeDotFileForCountingPieces (graph, edgeColor);          //uncomment to make dot file
    return noOfConnectedComponents;

}

//diameter program functions begin here

void findDiameter (GRAPH *graph) {

    int i, j;
    int index_i, index_j;
    int maxDistance = 0;

    for (i = 0; i < graph->n; i++) {

        for (j = 0; j < graph->n; j++) {
            //if (i == 3)
                //printf("\ndistance for (%d,%d)\n", i, j);
            if (BFS (graph, i, j) > maxDistance) {
            //if (findShortestPath (graph, i, j) > maxDistance) {

                maxDistance = BFS (graph, i, j);
                //maxDistance = findShortestPath (graph, i, j);
                index_i = i;
                index_j = j;

            }

        }

    }
    printf("maxDistance (%d, %d) = %d\n", index_i, index_j, maxDistance);
    findShortestPath (graph, index_i, index_j);
    //makeDotFileForDiameter (graph);

}

//eulerian program functions starts here

int isDegreeEven (GRAPH *graph, int degree[]) {

    int i, j;

    for (i = 0; i < graph->n; i++) {

        for (j = 0; j < graph->n; j++) {

            degree[i] += graph->a[i][j];

        }
        if (degree[i] % 2 != 0) return 0;             //a vertex has an odd degree

    }
    return 1;                   //all vertices have degree even, returning 1

}
void makeDotFileForEulerian (GRAPH *graph, int a_d[][32]) {

    int i,j;
    int check;
    char one[32];
    char str[32];

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, "Eulerian.dot");

    int n = graph->n;
    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form
                                                       //of the adjacency matrix

    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT

        for (j = i; j < graph->n; j++) {

            if (graph->a[i][j] == 1) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);

                if (a_d[i][j] == 1 || a_d[j][i] == 1) {
                    fprintf(fpWrite, "[color = %s] ", "red");
                }

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }
        }

        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }

        }
    }

    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}

void findEulerianCircuit (GRAPH *graph, int starting_node, int a_d[][32],int degree[]) {

    int v;
    //int path[132];                      //to store vertices in order of their eulerian circuit
    int count_path = 0;                 //to count the vertices entry in the array 'path'
    int pre_starting_node = -1;         //to store the vertex adjacent to starting node when
                                        //starting node has degree left to be 1
    Node *head = (Node *) malloc(sizeof(Node));
    Node *head_d = head;
    Node *p;

    Queue *queue = createQueue ();      //creating queue

    enQueue (queue, starting_node);
    head->data = starting_node;
    head->next = NULL;
    //path[count_path++] = starting_node;   //first element of the path array is the
                                        //starting index

    printf("EULERIAN CIRCUIT goes as follows : \n");

    while (!isQueueEmpty(queue)) {

        int currentNode = deQueue (queue);          //finding current node

        for (v = 0; v < graph->n; v++) {
            // printf("a[%d][%d] = %d ", currentNode, v, graph->a[currentNode][v]);
            // printf("a_d[%d][%d] = %d\n", currentNode, v, a_d[currentNode][v]);
            if (graph->a[currentNode][v] != 0) {

                if (a_d[currentNode][v] == 0) {

                    if (v == starting_node && degree[currentNode] != 1) continue;

                    /*if (currentNode != starting_node && degree[v] == 2
                         && a_d[starting_node][v] == 0 && graph->a[starting_node][v] != 0
                        && degree[currentNode]>1 && degree[starting_node] == 1)
                        {
                            printf("(%d, %d)\n", currentNode, v);
                            continue;
                        }*/
                    /*if (degree[starting_node] == 1) {

                        if (pre_starting_node == -1) {
                            pre_starting_node = findPreStartingNode (graph, starting_node, a_d);
                            printf("pre_starting_node = %d\n", pre_starting_node);
                        }

                        if (pre_starting_node == v && degree[currentNode] > 1) continue;

                    }
*/
                    enQueue (queue, v);
                    //path[count_path++] = v;         //storing vertex 'v' in the array 'path'
                    p = (Node *) malloc(sizeof(Node));
                    p->data = v;
                    p->next = NULL;
                    head_d->next = p;
                    head_d = p;

                    a_d[currentNode][v] = 1;
                    a_d[v][currentNode] = 1;
                    degree[v]--;
                    degree[currentNode]--;
                    break;

                }

            }
        }


    }

    head_d->next = head;

    p = head;
    Node *p_d;
    int currentNode;
    //int parent[32];

   /* do {

        if (degree[p->data] != 0) {

            //printf("%d ", p->data);
            //currentNode = p->data;
            enQueue (queue, p->data);
            //parent[p->data] = -1;

            while (!isQueueEmpty (queue)) {

                currentNode = deQueue (queue);
                printf("%d ", currentNode);

                for (v = 0; v < graph->n; v++) {

                    if (a_d[currentNode][v] == 0 && graph->a[currentNode][v] != 0) {

                        //parent[v] = currentNode;
                        a_d[currentNode][v] = 1;
                        a_d[v][currentNode] = 1;

                        // currentNode = v;
                        //printf("v = %d ", v);

                        degree[currentNode]--;
                        degree[v]--;

                        if (degree[v] > 1)  {

                            //printf("enQueuing %d\n", v);
                            enQueue (queue, v);
                            continue;

                        }
                        break;
                        if (v == graph->n - 1 && graph->a[p->data][v] == 0) {
                            v = 0;
                        }

                    }
            }

            }

            a_d[currentNode][p->data] = 1;
            a_d[p->data][currentNode] = 1;
        }

        printf("%d ", p->data);

        p = p->next;

    } while (p != head);*/

    /*for (v = 0; v < count_path; v++) {

        printf("%d ", path[v]);

    }*/

    do {

        if (degree[p->data] != 0) {

            printf("%d ", p->data);
            int currentNode = p->data;

            for (v = 0; v < graph->n; v++) {

                if (a_d[currentNode][v] == 0 && graph->a[currentNode][v] != 0) {

                    a_d[currentNode][v] = 1;
                    a_d[v][currentNode] = 1;

                    currentNode = v;
                    printf("%d ", v);

                    degree[currentNode]--;
                    degree[v]--;
                    if (v == graph->n - 1 && graph->a[p->data][v] == 0) {
                        v = 0;
                    }

                }
            }
            a_d[currentNode][p->data] = 1;
            a_d[p->data][currentNode] = 1;
        }

        printf("%d ", p->data);

        p = p->next;

    } while (p != head);

    printf("\n");
    makeDotFileForEulerian (graph, a_d);

}

//six coloring program functions begin here

void makeDotFileForSixColoring (GRAPH *graph, int vertexColor[]) {

    char one[32];
    char str[32];
    int n = graph->n;
    int i,j;
    int check;
    char color[][15] = {"red", "blue", "green", "cyan", "orange", "yellow"};

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, "SixColored.dot");

    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT

        for (j = i; j < graph->n; j++) {

            if (graph->a[i][j] != 0) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }

                else {
                    fprintf(fpWrite, ";\n");
                }

                check = 1;

            }

        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }

            else {
                fprintf(fpWrite, "\n");
            }

        }

    }
    for (i = 0; i < graph->n; i++) {

        fprintf(fpWrite, "      ");
        fprintf(fpWrite, "%d  ", i);
        fprintf(fpWrite, "[color = %s, style = filled] ", color[vertexColor[i]]);

        if (i == graph->n - 1)
            fprintf(fpWrite, "\n");
        else
            fprintf(fpWrite, ";\n");


    }

    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}

int isColorSame (GRAPH *graph, int vertexColor[], int v) {

    int i;

    for (i = 0; i < graph->n; ++i)
        if ((graph->a[v][i] == 1 || graph->a[i][v] == 1) && vertexColor[v] == vertexColor[i]) return i;             //color of vertex adjacent
                                                                    //to v has same color
    return -1;               //no adjacent vertex of v has the same color as v

}

void coloringWithSixColors (GRAPH *graph) {

    int color_index = 0;                //to store
    int vertexColor [32];
    int i;

    for (i = 0; i < graph->n; i++) vertexColor[i] = -1;

    int root = 0;
    int total_colors = 6;

    vertexColor[root] = color_index++;

    int visited[32] = {0};          //making all to be unchecked (0)

    visited[root] = 1;              //making root as visited
    int j;

    for (j = 0; j < graph->n; j++) {

        for (i = 0; i < graph->n; i++) {

            if (!visited[i] && graph->a[j][i] != 0) {

                //enQueue (queue, i);
                visited[i] = 1;         //marking node as visited
                vertexColor[i] = color_index % total_colors;
                printf("\nisColorSame = %d\n", isColorSame (graph, vertexColor, i));
                while (isColorSame (graph, vertexColor, i) != -1) {      //checking if the adjacent vertices have same color or not
                    printf("inside loop -> %d\n", i);
                    vertexColor[i] = (color_index++) % total_colors;
                }
                printf("COLORING OF %d : ", i);
                printf("vertexColor[%d] = %d\n", i, vertexColor[i]);
                color_index = 0;

            }

        }

    }

    // for (i = 0; i < graph->n; i++) {
    //     printf("vertexColor[%d] = %d\n", i, vertexColor[i]);
    // }
    makeDotFileForSixColoring (graph, vertexColor);

}

//dijkstra program functions begin here

//function to find if any vertex is unvisited
int hasAnyVertexUnvisited (GRAPH *graph, int visited[]) {

    int i = -1;

    while (i++ < graph->n)
        if (visited[i] == 0) return 1;

    return 0;

}

//function to return the vertex which has minimum distance and still unvisited
int getMinimumDistanceVertex (GRAPH *graph, int dist[], int visited[]) {

    int min =  INT_MAX;         //initializing min to be INT_MAX
    int min_index = 0;
    int i;

    for (i = 0; i < graph->n; i++) {

        if (!visited[i] && dist[i] < min) {

            min = dist[i];
            min_index = i;

        }

    }

    return min_index;               //returning vertex which has least distance and unvisited

}

//to print path for shortest path using recursion
void printPathForDijkstra (GRAPH *graph, int parent[], int dest, int a_d[][32]) {


    if (parent[dest] == -1) return;

    printPathForDijkstra (graph, parent, parent[dest], a_d);
    printf("%d ", dest);

    a_d[parent[dest]][dest] = - 5;          //to store edge between parent[dest] & dest for the dot file
    a_d[dest][parent[dest]] = - 5;          //to store edge between parent[dest] & dest for the dot file

}

//printing the shortest path
void printShortestPathForDijkstra (GRAPH *graph, int root, int dest, int parent[], int dist, int a_d[][32]) {

    printf("%-9s%-10s%-10s","Vertex", "Distance", "Path");
    printf("\n%d -> %d   %-10d%d ", root, dest, dist, root);

    // printf("PATH (%d -> %d) :  ", root, dest);
    // printf("%d ", root);
    printPathForDijkstra (graph, parent, dest, a_d);
    printf("\n");
    //printf("\nDistance (%d -> %d) : %d\n", root, dest, dist);

}

//to make dot file for dijkstra
void makeDotFileForDijkstra (GRAPH *graph, int root, int dest, int dist[], int a_d[][32]) {

    char one[32];
    char str[32];
    int n = graph->n;
    int i,j;
    int check;
    int marked[32] = {0};

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, "Dijkstra.dot");

    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    //coloring root vertex in green color
    fprintf(fpWrite, "      ");
    fprintf(fpWrite, "%d  ", root);
    fprintf(fpWrite, "[color = %s, style = filled];\n", "green");

    //coloring destination vertex in blue color
    fprintf(fpWrite, "      ");
    fprintf(fpWrite, "%d  ", dest);
    fprintf(fpWrite, "[color = %s, style = filled];\n", "blue");

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT

        for (j = i; j < graph->n; j++) {

            if (graph->a[i][j] != 0) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);

                //checking if the given pair of vertices (i, j) comes in the path together or not
                if (a_d[i][j] == -5 || a_d[j][i] == -5)
                    fprintf(fpWrite, "[color=red,style = bold] [label = %d, fontcolor = navyblue,"
                                        "fontsize = 24] ", graph->a[i][j]);

                else
                    fprintf(fpWrite, "[label = %d] ", graph->a[i][j]);

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }

                else {
                    fprintf(fpWrite, ";\n");
                }

                check = 1;

            }

        }

        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }

            else {
                fprintf(fpWrite, "\n");
            }

        }

    }

    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}

int dijkstra (GRAPH *graph, int root, int dest) {

    int dist[32] = {[0 ... 31] = INT_MAX};          //new way to declare all values of
                                                    //dist from 0-31 = INT_MAX
    int parent[32];                         //to store parent node of a vertex
    int visited[32] = {0};                  //to mark a vertex to be visited or unvisited
                                            //INITIALLY all vertices are unvisited
    int i, j;
    int a_d[32][32];                        //to make a copy of adjacency matrix

    dist[root] = 0;                         //distance of root from itself is zero
    parent[root] = -1;                      //setting parent of root to be -1 (NONE)

    while (hasAnyVertexUnvisited(graph, visited)) {                     //runs until no vertex is unvisited

        int u = getMinimumDistanceVertex (graph, dist,visited);        //vertex which has least distance & unvisited is chosen
        //printf("u = %d\n", u);
        visited[u] = 1;             //making vertex 'u' to be visited

        if (u == dest) break;               //if destination vertex is found

        for (i = 0; i < graph->n; i++) {

            int dist_i = dist[u] + graph->a[u][i];              //distance of vertex i via vertex u

            if (graph->a[u][i] != 0 && !visited[i] && dist_i < dist[i]) {

                dist[i] = dist_i;
                parent[i] = u;

            }       //checking if new path to vertex i via vertex u has shorter length than
                    //existing length from root

        }

    }

    //copying adjacency matrix into an 2-d array 'a_d'
    for (i = 0; i < graph->n; i++) {
        for (j = 0; j < graph->n; j++) {
            a_d[i][j] = graph->a[i][j];
        }
    }

    printShortestPathForDijkstra (graph, root, dest, parent, dist[dest], a_d);  //to print shortest path
    makeDotFileForDijkstra (graph, root, dest, dist, a_d);      //to make dot file for dijkstra

    return dist[dest];      //returning the shortest distance

}

//dfs program functions begin here

void makeDotFileForDfs (GRAPH *graph, int path[][32], int root) {

    char one[32];
    char str[32];
    int n = graph->n;
    int i,j;
    int check;

    strcpy(one, graph->fileName);
    strcpy(str, one);
    strcat(str, "Dfs.dot");

    FILE *fpWrite = fopen(str, "w");                   //creating/opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    //coloring root vertex in green color
    fprintf(fpWrite, "      ");
    fprintf(fpWrite, "%d  ", root);
    fprintf(fpWrite, "[color = %s, style = filled];\n", "green");

    for (i = 0; i < graph->n; i++) {

        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT

        for (j = i; j < graph->n; j++) {
            printf("(%d, %d) \n", i, j);
            if (graph->a[i][j] != 0) {

                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);

                if (path[i][j] == -5 || path[j][i] == -5) {
                    fprintf(fpWrite, "[color=red] ");
                }

                if (j == graph->n -1 && i == graph->n-1) {
                    fprintf(fpWrite, "\n");
                }

                else {
                    fprintf(fpWrite, ";\n");
                }

                check = 1;

            }

        }printf("\n" );
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE

            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != graph->n -1) {
                fprintf(fpWrite, ";\n");
            }

            else {
                fprintf(fpWrite, "\n");
            }

        }

    }

    fprintf(fpWrite, "}");
    fclose (fpWrite);
    printf("DOT FILE CREATED SUCCESSFULLY...\n");

}

void dfsUsingStack (GRAPH *graph, int root) {

    int i;                              //loop counter
    int visited[32] = {0};              //to see if a vertex is visited or not
    int dfsPath[32][32] = {0};          //to store the edges in the dfs tree
    int prevNode = -1;

    Stack *stack = createStack (stack);

    push(stack, root);
    visited[root] = 1;

    printf("PATH IN DFS TREE USING STACKS IS AS FOLLOWS : \n" );

    while (isStackEmpty (stack)) {

        int currentNode = pop (stack);
        printf("%d ", currentNode);
        visited[currentNode] = 1;

        if (prevNode != -1) {

            dfsPath[prevNode][currentNode] = -5;
            dfsPath[currentNode][prevNode] = -5;

        }

        prevNode = currentNode;

        for (i = 0; i < graph->n; i++)
            if (!visited[i] && graph->a[currentNode][i] != 0) {
                push (stack, i);
                visited[i] = 1;
            }

    }

    printf("\n");
    makeDotFileForDfs (graph, dfsPath, root);

}

void dfsUsingRecursion_f (GRAPH *graph, int root, int visited[],int prev, int parent[], int dfsPath[][32]) {

    visited[root] = 1;

    //parent[root] = prev;

    if (prev != -1 && graph->a[prev][root] != 0) {
        dfsPath[prev][root] = -5;
        dfsPath[root][prev] = -5;
    }
    //printf("(%d, %d)\n", prev, root);

    prev = root;

    printf("%d ",root);
    //int index;

    int i;
    for (i = 0; i < graph->n; i++) {

        // if (root == 8) {
        //     printf("visited[%d] = %d, graph->a[%d][%d] = %d\n", i, visited[i], root, i, graph->a[root][i]);
        // }
        if (!visited[i] && graph->a[root][i] != 0) {
            //index = i;
            dfsUsingRecursion_f (graph, i, visited, prev, parent, dfsPath);
        }

    }
    // if (hasAnyVertexUnvisited (graph, visited)) {
    //     dfsUsingRecursion_f (graph, index, visited, prev, parent);
    // }
    //return prev;
}

void dfsUsingRecursion (GRAPH *graph, int root, int dfsPath[][32]) {

    int visited[32] = {0};
    int parent[32];
    int prev = -1;

    //parent[root] = -1;
    printf("PATH IN DFS TREE USING RECURSION IS AS FOLLOWS : \n");

    dfsUsingRecursion_f (graph, root, visited, prev, parent, dfsPath);
    printf("\n" );
    makeDotFileForDfs (graph, dfsPath, root);

}

void findHamiltonianNew (GRAPH *graph) {

    int dfsPath[][32] = {0};

    dfsUsingRecursion (graph, 0, dfsPath);
    // printf("0\n");

}
