#include<stdio.h>
#include<stdlib.h>

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Structure to represent a graph. A graph is an array of adjacency lists.
// Size of the array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size of the array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src.
    // The node is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// DFS utility function
void DFSUtil(int v, int visited[], struct Graph* graph) {
    // Mark the current node as visited and print it
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl) {
        int adj = pCrawl->dest;
        if (!visited[adj])
            DFSUtil(adj, visited, graph);
        pCrawl = pCrawl->next;
    }
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void DFS(struct Graph* graph, int v) {
    // Mark all the vertices as not visited
    int *visited = (int *)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited, graph);
}

int main() {
    // Create a graph given in the above diagram
    int V = 12;  // Total vertices
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 10);
    addEdge(graph, 7, 11);

    printf("DFS starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
