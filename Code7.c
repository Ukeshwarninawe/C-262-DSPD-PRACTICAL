#include <stdio.h>
#include <stdlib.h>

#define N 9   // Number of nodes

int graph[N][N]; // Adjacency matrix
int visited[N];

// Function to add edge between two nodes (undirected)
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Breadth First Search (BFS)
void BFS(int start) {
    int queue[N], front = 0, rear = 0;
    for (int i = 0; i < N; i++) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node + 1); // +1 for human-readable numbering

        // Add neighbors (low → high)
        for (int i = 0; i < N; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Depth First Search (DFS)
void DFS(int node) {
    printf("%d ", node + 1);
    visited[node] = 1;

    // Visit neighbors (high → low)
    for (int i = N - 1; i >= 0; i--) {
        if (graph[node][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    // Build 3x3 grid connections
    addEdge(0, 1); addEdge(1, 2);
    addEdge(3, 4); addEdge(4, 5);
    addEdge(6, 7); addEdge(7, 8);
    addEdge(0, 3); addEdge(3, 6);
    addEdge(1, 4); addEdge(4, 7);
    addEdge(2, 5); addEdge(5, 8);

    printf("Starting from node 1\n\n");

    BFS(0);

    for (int i = 0; i < N; i++) visited[i] = 0;
    printf("DFS Order: ");
    DFS(0);
    printf("\n");

    return 0;
}