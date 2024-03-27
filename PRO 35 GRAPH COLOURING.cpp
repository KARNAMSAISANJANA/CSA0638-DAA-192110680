#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

// Function to check if it's safe to color the vertex v with color c
bool isSafe(int graph[V][V], int v, int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve graph coloring problem using backtracking
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack: Remove color assignment if it doesn't lead to a solution
        }
    }

    return false; // No feasible color can be assigned to this vertex
}

// Function to solve graph coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all vertices as uncolored
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printf("Solution exists. The coloring of the vertices is:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }

    return true;
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors available

    graphColoring(graph, m); // Solve the graph coloring problem

    return 0;
}
