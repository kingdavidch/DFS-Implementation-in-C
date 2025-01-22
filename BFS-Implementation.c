#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 13

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], bool visited[], int vertex, int V) {
    printf("%d ", vertex);
    visited[vertex] = true;
    
    for (int i = 1; i < V; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, visited, i, V);
        }
    }
}

int main() {
    int V = 13; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    // Add edges according to the given graph
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][5] = graph[5][2] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[3][6] = graph[6][3] = 1;
    graph[4][7] = graph[7][4] = 1;
    graph[5][7] = graph[7][5] = 1;
    graph[5][9] = graph[9][5] = 1;
    graph[6][8] = graph[8][6] = 1;
    graph[7][10] = graph[10][7] = 1;
    graph[8][10] = graph[10][8] = 1;
    graph[9][11] = graph[11][9] = 1;
    graph[10][12] = graph[12][10] = 1;
    graph[11][12] = graph[12][11] = 1;

    bool visited[MAX_VERTICES] = {false};
    
    printf("DFS starting from vertex 1: ");
    DFS(graph, visited, 1, V);
    
    return 0;
}
