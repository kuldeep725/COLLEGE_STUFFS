/*
    Functions to test the functions in graph library graphlib.c
    Deepak R
*/

#include <stdio.h>

#include "graphlib.h"


/*
	Read a graph G from file.
	Create a tree T to store a BFS stree in G
	Call the BFS function to store a BFS of G in T
	Get the adjacency matrix of T
	Create a dot file highlighting T in H
	Free all the data structures created
*/  

int main()
{
    struct graph *G, *H;
    struct tree *T;
    int i;

    G = read_graph();		
    T = bfs_tree(G, 3);
    H = tree_to_graph(T);

    write_dot_file2(G, H);

    delete_graph(G);
    delete_graph(H);

    return 0;
}
