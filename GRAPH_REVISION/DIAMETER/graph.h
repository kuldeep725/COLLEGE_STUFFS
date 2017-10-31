#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct GRAPH {
    int a[32][32];
    char fileName[32];
    int n;
} GRAPH;

int BFS (GRAPH *graph, int, int);
GRAPH * readAdjacentMatrix (GRAPH *);
void makeDotFile (GRAPH *);

//hamiltonian program functions declare here
void findHamiltonian (GRAPH *);
int hamCycle (GRAPH *);
void makeDotFileForHamiltonian (GRAPH *, int[]);
int hamCycleUtil (GRAPH *, int[], int);
int isSafe (int , GRAPH *, int [], int);
void printSolution (GRAPH *, int[]);

//pathfinder program functions declare here
void makeDotFileForPathFinder (GRAPH *);
void printPath (GRAPH *, int[], int, int *);
void printShortestPath (GRAPH *, int, int, int[], int *);
int findShortestPath (GRAPH *, int, int);

//shortRed program functions declare here
void makeDotFileForShortRed (GRAPH  *);
int countRedEdges (GRAPH *, int, int[]);
void findShortestPathWithRed (GRAPH *, int, int);

//counting_pieces program functions declare here
int calculateNumberOfConnectedComponents (GRAPH *);
int haveVerticesLeft (GRAPH *, int []);

//diameter program functions declare here
void findDiameter (GRAPH *);