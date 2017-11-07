#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

//when linked list is to be used
typedef struct Node {

    int data;
    struct Node *next;

} Node;

//structure to keep basic elements of graph
typedef struct GRAPH {

    int a[32][32];
    char fileName[32];
    int n;

} GRAPH;

//(1) basic functions in graph
int BFS (GRAPH *graph, int, int);
GRAPH * readAdjacentMatrix (GRAPH *);
void makeDotFile (GRAPH *);

//(2)hamiltonian program functions declare here
void findHamiltonian (GRAPH *);
int hamCycle (GRAPH *);
void makeDotFileForHamiltonian (GRAPH *, int[]);
int hamCycleUtil (GRAPH *, int[], int);
int isSafe (int , GRAPH *, int [], int);
void printSolution (GRAPH *, int[]);

//(3)pathfinder program functions declare here
void makeDotFileForPathFinder (GRAPH *);
void printPath (GRAPH *, int[], int);
void printShortestPath (GRAPH *, int, int, int[], int);
int findShortestPath (GRAPH *, int, int);

//(4)shortRed program functions declare here
void makeDotFileForShortRed (GRAPH  *);
int countRedEdges (GRAPH *, int, int[]);
void findShortestPathWithRed (GRAPH *, int, int);

//(5)counting_pieces program functions declare here
int calculateNumberOfConnectedComponents (GRAPH *);
int haveVerticesLeft (GRAPH *, int []);

//(6)diameter program functions declare here
void findDiameter (GRAPH *);

//(7)eulerian program functions declare here
int isDegreeEven (GRAPH *, int []);
void findEulerianCircuit (GRAPH *, int, int[][32], int[]);
void makeDotFileForEulerian (GRAPH *, int [][32]);

//(8)color_6 program functions declare here
void coloringWithSixColors (GRAPH *graph);
int isColorSame (GRAPH *, int [], int );
void makeDotFileForSixColoring (GRAPH *, int []);

//(9)dijkstra program functions declare here
int hasAnyVertexUnvisited (GRAPH *, int []);
int getMinimumDistanceVertex (GRAPH *, int [], int []);
void printPathForDijkstra (GRAPH *, int [], int , int [][32]);
void printShortestPathForDijkstra (GRAPH *, int , int , int [], int , int [][32]);
void makeDotFileForDijkstra (GRAPH *, int , int , int [], int [][32]);
int dijkstra (GRAPH *, int, int);

void dfsUsingStack (GRAPH *, int);
void dfsUsingRecursion (GRAPH *, int, int[][32]);

void findCutVertices (GRAPH *);