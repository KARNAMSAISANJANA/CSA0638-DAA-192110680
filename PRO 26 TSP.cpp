#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices (cities)

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the TSP using dynamic programming
int tsp(int graph[][V], int mask, int pos, int dp[][V]) {
    // If all cities have been visited, return the cost of returning to the starting city
    if (mask == (1 << V) - 1) {
        return graph[pos][0];
    }

    // If the subproblem has already been computed, return the result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INT_MAX;

    // Try to visit each unvisited city
    for (int city = 0; city < V; city++) {
        // Check if the city has already been visited
        if ((mask & (1 << city)) == 0) {
            int newMask = mask | (1 << city);
            int newCost = graph[pos][city] + tsp(graph, newMask, city, dp);
            minCost = min(minCost, newCost);
        }
    }

    // Memoize the result
    dp[mask][pos] = minCost;

    return minCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // dp[mask][pos] stores the minimum cost of visiting all cities in 'mask', starting from 'pos'
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    int startCity = 0; // Starting city

    // Find the minimum cost of visiting all cities starting from the startCity
    int minCost = tsp(graph, 1 << startCity, startCity, dp);

    printf("Minimum cost for TSP: %d\n", minCost);

    return 0;
}
