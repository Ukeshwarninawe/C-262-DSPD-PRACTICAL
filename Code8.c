#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 9999

void dijkstra(int n, int graph[MAX][MAX], int start) {
    int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];
    int count, mindistance, nextnode, i, j;

    // Create cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = graph[i][j];

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INF;

        // Next node = node with minimum distance
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        // Update distance of neighboring nodes
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Print shortest paths and distances
    printf("\nShortest distances from node %d:\n", start + 1);
    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Node %d is unreachable (distance = -1)\n", i + 1);
        else {
            printf("To node %d = %d\tPath: %d", i + 1, distance[i], i + 1);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j + 1);
            } while (j != start);
            printf("\n");
        }
    }
}

int main() {
    int n, graph[MAX][MAX], i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (1 to %d): ", n);
    scanf("%d", &start);
    start--; // adjust for 0-based index

    dijkstra(n, graph, start);

    return 0;
}