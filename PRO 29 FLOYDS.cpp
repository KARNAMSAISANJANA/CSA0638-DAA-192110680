#include <stdio.h>

#define INF 99999
#define V 4 // Number of vertices

// Function to perform Floyd's algorithm to find all-pairs shortest paths
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix with the given graph
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update the distance matrix by considering all intermediate vertices
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    floydWarshall(graph);

    return 0;
}
