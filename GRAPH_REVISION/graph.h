#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct GRAPH {
    int a[32][32];
    char fileName[32];
    int n;
} GRAPH;

GRAPH * readAdjacentMatrix (GRAPH *);
int BFS (GRAPH *, int, int);
void makeDotFile (GRAPH *);

void findHamiltonian (GRAPH *);
int hamCycle (GRAPH *);
void makeDotFileForHamiltonian (GRAPH *, int[]);
int hamCycleUtil (GRAPH *, int[], int);
int isSafe (int , GRAPH *, int [], int);
void printSolution (GRAPH *, int[]);

void printPath (GRAPH *, int [], int, int *);
void printShortestPath (GRAPH *, int, int, int[], int *);
void findShortestPath (GRAPH *, int, int);
void makeDotFileForPathFinder (GRAPH *);

void makeDotFileForTry (GRAPH *);
void findShortestPathWithRed (GRAPH *, int, int);
int countRedEdges (GRAPH *, int, int[]);
