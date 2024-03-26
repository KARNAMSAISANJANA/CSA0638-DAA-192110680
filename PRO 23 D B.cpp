#include <stdio.h>

#define MAX 100

// Function to calculate binomial coefficient
int binomialCoefficient(int n, int k) {
    int C[MAX][MAX];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n, k;
    printf("Enter the value of n and k (n choose k): ");
    scanf("%d %d", &n, &k);
    printf("Binomial Coefficient of %d choose %d is %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}
