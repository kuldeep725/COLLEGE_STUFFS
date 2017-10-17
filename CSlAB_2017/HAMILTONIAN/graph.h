#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct GRAPH {
    int a[32][32];
    char fileName[32];
    int n;
} GRAPH;

typedef struct HAMILTONIAN {
    int x;
    struct HAMILTONIAN *next;
    struct HAMILTONIAN *prev;
} HAMILTONIAN;
