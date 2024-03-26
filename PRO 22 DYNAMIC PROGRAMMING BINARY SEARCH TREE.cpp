#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of probabilities from i to j
float sum(float freq[], int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Function to find the optimal binary search tree cost
float optimalBST(float freq[], int n) {
    // Create a 2D table to store the costs of optimal BSTs
    float cost[n][n];

    // Initialize all values in the table to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = 0;

    // For single node trees, the cost is the frequency of that node
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Calculate the cost for chains of increasing length
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval [i, j] as root
            for (int r = i; r <= j; r++) {
                // Calculate the cost if key 'r' becomes the root of this subtree
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    // The cost of the optimal BST is stored in cost[0][n-1]
    return cost[0][n - 1];
}

int main() {
    float keys[] = {10, 12, 20};
    float freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Cost of optimal BST is: %f\n", optimalBST(freq, n));

    return 0;
}
