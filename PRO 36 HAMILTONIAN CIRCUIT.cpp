#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

int path[V]; // Stores the Hamiltonian path/circuit
int graph[V][V]; // Graph representation

// Function to check if the vertex can be added to the Hamiltonian path
bool isSafe(int v, int pos, int path[V]) {
    if (graph[path[pos - 1]][v] == 0) // Check if this edge is present in the graph
        return false;

    for (int i = 0; i < pos; i++) // Check if the vertex is already included
        if (path[i] == v)
            return false;

    return true;
}

// Function to find the Hamiltonian path/circuit
bool hamiltonianUtil(int path[], int pos) {
    if (pos == V) { // If all vertices are included in the path
        if (graph[path[pos - 1]][path[0]] == 1) // If there is an edge from the last included vertex to the first
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;

            if (hamiltonianUtil(path, pos + 1) == true)
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

// Function to find and print Hamiltonian path/circuit
void hamiltonian() {
    int path[V];

    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start from the 0th vertex

    if (hamiltonianUtil(path, 1) == false) {
        printf("Hamiltonian path does not exist\n");
        return;
    }

    printf("Hamiltonian circuit exists: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Return to the starting vertex
}

int main() {
    // Example graph representation
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonian(); // Find and print Hamiltonian path/circuit
    return 0;
}
