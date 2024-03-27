#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Global variables
int set[MAX_SIZE];
bool solution[MAX_SIZE];
int n, targetSum;

// Function to print the subsets that sum up to targetSum
void printSubset() {
    printf("Subset with sum equal to %d: { ", targetSum);
    for (int i = 0; i < n; i++) {
        if (solution[i]) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

// Function to recursively find subsets with sum equal to targetSum
void sumOfSubsets(int currentSum, int currentIndex) {
    // If currentSum is equal to targetSum, print the current subset
    if (currentSum == targetSum) {
        printSubset();
        return;
    }

    // If currentIndex exceeds array bounds or currentSum exceeds targetSum, return
    if (currentIndex >= n || currentSum > targetSum) {
        return;
    }

    // Include the current element in the subset
    solution[currentIndex] = true;
    sumOfSubsets(currentSum + set[currentIndex], currentIndex + 1);

    // Exclude the current element from the subset
    solution[currentIndex] = false;
    sumOfSubsets(currentSum, currentIndex + 1);
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum equal to %d are:\n", targetSum);
    sumOfSubsets(0, 0); // Start with initial sum 0 and index 0

    return 0;
}
