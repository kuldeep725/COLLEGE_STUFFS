/*
    Header file for graphlib.c
*/

// ** Data Structures 

// A data structure to store the adjacency matrix of a graph
struct graph
{
    char name[100];
    int  num_vertices;
    int  num_edges;
    int  **adj_matrix; 
        // Memory for the adjacency matrix should be dynamically allocated
        // using the create_graph() function.
};

// One node of tree, with a pointer to parent if it has one
struct tree_node
{
    int key;
    int level;	// Distance from the root
    struct tree_node *parent; //NULL if root
};

// Data structure for a tree in which 
struct tree
{
    char name[100];
    int root;
    int num_vertices;
    struct tree_node *nodes; 
		// Memory for num_vertices nodes will be allocated by the 
		// create_tree() function and then the nodes can be 
		// accessed as an array
    int *visited;
		// Memory for num_vertices integers will be allocated by the 
		// create_tree() function and then the flags can be 
		// accessed as an array. 
		// The flag will be 1 for a node that is reachable from the root
		// and 0 for other vertices
};

// ** Function prototypes

// Function to create a tree with the given name and number of vertices
// and allocate the required memory  
// and initialize the visited flags array to zeros
struct tree* create_tree(char *name, int n);

// Function to create a graph with the given name and number of vertices
// and allocate the required memory for the adjacency matrix 
// and initialize it to all zeros
struct graph* create_graph(char *name, int n);

// Function to convert a tree structure to adjacency matrix
struct graph* tree_to_graph(struct tree* T);

// A helper function to print the entire adjacency matrix of a graph
void print_adj_matrix(struct graph *G);

// An interface function which will prompt the user to enter the
// name of a file containing the adjacency matrix of a graph 
// and then create and return the pointer to a graph data structure
// populated with data from the file
struct graph* read_graph();

// Write the given graph as a dot file
// The filename is determined by the name of the graph
void write_dot_file(struct graph *G);

// The second graph is assumed to be a subgraph of the first.
// A dot file is written with the edges of the first graph
// in default colour and second in red
// The filename is determined by the names of the two graphs
void write_dot_file2(struct graph *G, struct graph *H);

// Function to free the memory allocated
void delete_graph(struct graph *G);

// Function to do a BFS traversal of the given graph from the
// given node and store the resulting tree in a tree data structure
// A pointer to the resulting tree is returned
struct tree* bfs_tree(struct graph *G, int start);

