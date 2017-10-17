/*

    Commonly used data structures and functions for graph algorithms
    Deepak R
    (Modified from code written originally by Lijo M. Jose)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "graphlib.h"

struct tree* create_tree(char *name, int n)
{
    struct tree *T;
    int i;

    T = (struct tree*) malloc(sizeof(struct tree));

    T->num_vertices = n;
    strcpy(T->name, name);

    // Allocate memory for nodes and visited flag array
    T->nodes    = (struct tree_node*) malloc(n * sizeof(struct tree_node));
    T->visited  = (int*) malloc(n * sizeof(int));
    
    // Initialize the keys and flag array
    for(i = 0; i < n; i++)
    {
        T->nodes[i].key = i;
        T->visited[i] = 0;
    }

    return T;
}

struct graph* create_graph(char *name, int n)
{
    struct graph *G;
    int i, j;

    G = (struct graph*) malloc(sizeof(struct graph));

    G->num_vertices = n;
    G->num_edges = 0;
    strcpy(G->name, name);

    // Allocate memory for a 2D array
    G->adj_matrix = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
        G->adj_matrix[i] = (int *) malloc(n * sizeof(int));

    // Initialize the adjacency matrix to zeros
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            G->adj_matrix[i][j] = 0;

    return G;
}

struct graph* tree_to_graph(struct tree* T)
    {
        struct graph *G;
        int i, j;

        G = create_graph(T->name, T->num_vertices);

        for(i = 0; i < T->num_vertices; i++)
        {
            if(T->root == i)
                continue;
            if(T->visited[i] == 1)
            {
                j = T->nodes[i].parent->key;
                G->adj_matrix[i][j] = 1;
                G->adj_matrix[j][i] = 1;
                G->num_edges++;
            }

        }
        
        return G;
    }

void print_adj_matrix(struct graph *G)
{
    int i = 0, j = 0;
   
    printf("Adjacency matrix of graph %s (%d vertices , %d edges):\n", 
        G->name, G->num_vertices, G->num_edges);
 
    for(i = 0; i < G->num_vertices; i++)
    {
        for(j = 0; j < G->num_vertices; j++)
            printf("%d ", G->adj_matrix[i][j]);
        printf("\n");
    }
}

struct graph* read_graph()
{
    
	char f_name[100], g_name[100], g_type[10], entry;
    int num_vertices, num_edges, i, j;
	FILE *fptr;
    struct graph *G;

    G = (struct graph *) malloc(sizeof(struct graph));
	
	printf("Input file (containing adjacency matrix of the graph): ");
	scanf("%s",f_name);
	fptr = fopen(f_name, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "ERROR: Input file not found.\n");   
		exit(1);            
	}

	// Reading the header
	fscanf(fptr, " %s", g_name);
	fscanf(fptr, " %s", g_type);
	fscanf(fptr, " %d", &num_vertices);
    printf("Reading %s with %d vertices.\n", g_name, num_vertices);
	
    // Create memory for the graph
    G = create_graph(g_name, num_vertices);

	// Reading the adjacency matrix
    num_edges = 0;
	for(i = 0; i < G->num_vertices; i++)
    {
	    for(j = 0; j < G->num_vertices; j++)
        {
		    fscanf(fptr, " %c", &entry);
            G->adj_matrix[i][j] = (int) (entry - '0');
            num_edges += (entry - '0');
        }
	}
    G->num_edges = num_edges /2;

	fclose(fptr);

    return(G);
}

void write_dot_file(struct graph *G)
{
    
    int i, j;
	FILE *fptr;
    char f_name[104];

    strcpy(f_name, G->name);
    strcat(f_name, ".dot");
	
	fptr = fopen(f_name, "w");

	fprintf(fptr, "graph %s\n{\n", G->name);
	for(i = 0; i < G->num_vertices; i++)
    {
		fprintf(fptr,"\t%d;\n",i);
	    for(j = i+1; j < G->num_vertices; j++)
        {
		    if(G->adj_matrix[i][j] == 1)
				fprintf(fptr,"\t%d -- %d;\n",i,j);
        }
	}
	fprintf(fptr, "}\n", G->name);

	fclose(fptr);
}    

void write_dot_file2(struct graph *G, struct graph *H)
/*  H is assumed to be a subgraph of G. 
    The edges of H will be marked red.
*/
{
    
    int i, j;
	FILE *fptr;
    char f_name[250];

    sprintf(f_name, "%s_in_%s.dot", H->name, G->name);
	
	fptr = fopen(f_name, "w");

	fprintf(fptr, "graph %s\n{\n", G->name);
	for(i = 0; i < G->num_vertices; i++)
    {
		fprintf(fptr,"\t%d;\n",i);
	    for(j = i+1; j < G->num_vertices; j++)
        {
		    if(H->adj_matrix[i][j] == 1)
				fprintf(fptr,"\t%d -- %d [color=red];\n",i,j);
		    else if(G->adj_matrix[i][j] == 1)
				fprintf(fptr,"\t%d -- %d;\n",i,j);
        }
	}
	fprintf(fptr, "}\n", G->name);

	fclose(fptr);
}    

void delete_graph(struct graph *G)
{
    int i = 0;

    for(i = 0; i < G->num_vertices; i++)
        free(G->adj_matrix[i]);
    free(G->adj_matrix);
    free(G);
}

struct tree* bfs_tree(struct graph *G, int start)
/*  Returns the BFS tree in graph G rooted at vertex start
*/
{
    int i, current, level;
    struct tree *T;
    struct q_int *to_explore; // Queue of vertices to be explored
    char t_name[] = "BFS";
 
    T = create_tree(t_name, G->num_vertices);
    to_explore = create_q_int();

    T->nodes[start].level = 0;
    T->nodes[start].parent = NULL;
    T->root = start;
    T->visited[start] = 1;
    enqueue_q_int(to_explore, start);
    
    while(to_explore->length > 0)
    {
        current = dequeue_q_int(to_explore);
        for(i = 0; i < G->num_vertices; i++)
        {
            if(G->adj_matrix[current][i] == 0)
                continue;
            if(T->visited[i] == 1)
                continue;
         
            T->visited[i] = 1;
            T->nodes[i].level = T->nodes[current].level + 1;
            T->nodes[i].parent = &T->nodes[current];
            enqueue_q_int(to_explore, i);
        }
    }

    return T;
}

