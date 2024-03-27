#include <stdio.h>

// Function to print the pattern recursively
void printPattern(int row, int col) {
    // Base case: if row exceeds the number of rows to print
    if (row < 1)
        return;

    // If column number is less than or equal to current row number, print the column number
    if (col <= row) {
        printf("%d ", col);
        // Recur for the next column
        printPattern(row, col + 1);
    } else {
        printf("\n");
        // Recur for the next row
        printPattern(row - 1, 1);
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &numRows);

    // Call the printPattern function with the initial row and column as parameters
    printPattern(numRows, 1);

    return 0;
}
