#include <stdio.h>

// Function to find the minimum value sequence
void findMinSequence(int arr[], int n) {
    int min_sum = 0, current_sum = 0;
    int min_start = 0, min_end = 0;
    int current_start = 0;
    
    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        
        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_start = current_start;
            min_end = i;
        }
        
        if (current_sum > 0) {
            current_sum = 0;
            current_start = i + 1;
        }
    }
    
    printf("Minimum value sequence: ");
    for (int i = min_start; i <= min_end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum value sequence
void findMaxSequence(int arr[], int n) {
    int max_sum = 0, current_sum = 0;
    int max_start = 0, max_end = 0;
    int current_start = 0;
    
    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_start = current_start;
            max_end = i;
        }
        
        if (current_sum < 0) {
            current_sum = 0;
            current_start = i + 1;
        }
    }
    
    printf("Maximum value sequence: ");
    for (int i = max_start; i <= max_end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    findMinSequence(arr, n);
    findMaxSequence(arr, n);
    
    return 0;
}
