#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratio_b = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    if (ratio_a < ratio_b)
        return 1; // Sort in descending order
    else if (ratio_a > ratio_b)
        return -1;
    else
        return 0;
}

// Function to solve the Knapsack problem using a greedy approach
void knapsackGreedy(struct Item items[], int n, int capacity) {
    // Sort items based on their value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Final value of knapsack

    printf("Selected items:\n");

    for (int i = 0; i < n; i++) {
        // If adding the current item won't exceed capacity, add it to knapsack
        if (currentWeight + items[i].weight <= capacity) {
            printf("Item with value %d and weight %d\n", items[i].value, items[i].weight);
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            // If adding the current item exceeds capacity, break
            break;
        }
    }

    printf("Total value in the knapsack: %.2f\n", finalValue);
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsackGreedy(items, n, capacity);

    return 0;
}
