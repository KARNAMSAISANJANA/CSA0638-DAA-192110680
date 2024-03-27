#include <stdio.h>

#define ROWS 3
#define COLS 3

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCost(int cost[ROWS][COLS]) {
    int dp[ROWS][COLS];

    // Base case: Initialize the first cell of dp array
    dp[0][0] = cost[0][0];

    // Initialize the first column of dp array
    for (int i = 1; i < ROWS; i++)
        dp[i][0] = dp[i - 1][0] + cost[i][0];

    // Initialize the first row of dp array
    for (int j = 1; j < COLS; j++)
        dp[0][j] = dp[0][j - 1] + cost[0][j];

    // Build the dp array
    for (int i = 1; i < ROWS; i++) {
        for (int j = 1; j < COLS; j++) {
            dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Return the optimal cost
    return dp[ROWS - 1][COLS - 1];
}

int main() {
    int cost[ROWS][COLS] = {
        {1, 3, 5},
        {2, 1, 4},
        {5, 2, 1}
    };

    printf("Optimal cost: %d\n", minCost(cost));

    return 0;
}
