#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print Pascal's triangle
void printPascalTriangle(int numRows) {
    int i, j;
    for (i = 0; i < numRows; i++) {
        // Print spaces to align triangle properly
        for (j = 0; j < numRows - i - 1; j++) {
            printf("   ");
        }
        for (j = 0; j <= i; j++) {
            printf("%6d", binomialCoeff(i, j));
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    // Print Pascal's triangle with given number of rows
    printPascalTriangle(numRows);

    return 0;
}
