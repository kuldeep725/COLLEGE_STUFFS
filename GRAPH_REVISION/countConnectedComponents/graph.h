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

void findHamiltonian (GRAPH *);
int hamCycle (GRAPH *);
void makeDotFileForHamiltonian (GRAPH *, int[]);
int hamCycleUtil (GRAPH *, int[], int);
int isSafe (int , GRAPH *, int [], int);
void printSolution (GRAPH *, int[]);


void makeDotFileForPathFinder (GRAPH *);
void printPath (GRAPH *, int[], int, int *);
void printShortestPath (GRAPH *, int, int, int[], int *);
void findShortestPath (GRAPH *, int, int);

void makeDotFileForShortRed (GRAPH  *);
int countRedEdges (GRAPH *, int, int[]);
void findShortestPathWithRed (GRAPH *, int, int);

int calculateNumberOfConnectedComponents (GRAPH *);
int haveVerticesLeft (GRAPH *, int []);