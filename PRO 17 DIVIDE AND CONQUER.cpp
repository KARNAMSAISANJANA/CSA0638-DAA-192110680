#include <stdio.h>

// Function to find the maximum and minimum values in the list using divide and conquer
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftMax, leftMin, rightMax, rightMin;

    findMaxMin(arr, low, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);

    *max = (leftMax > rightMax) ? leftMax : rightMax;
    *min = (leftMin < rightMin) ? leftMin : rightMin;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, 0, arr_size - 1, &max, &min);

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}
