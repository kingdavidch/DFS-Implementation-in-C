#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 13

void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int V) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    visited[start] = true;
    queue[rear++] = start;
    
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        for (int i = 1; i < V; i++) {
            if (graph[vertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    // Same graph initialization as DFS
    int V = 13;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    // Add edges (same as DFS implementation)
    
    printf("BFS starting from vertex 1: ");
    BFS(graph, 1, V);
    
    return 0;
}
