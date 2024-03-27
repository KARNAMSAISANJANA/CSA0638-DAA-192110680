#include <stdio.h>

// Function to check if a number is perfect or not
int isPerfect(int num) {
    int sum = 0;

    // Find all proper divisors and sum them up
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // If the sum of proper divisors equals the number, it's perfect
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is perfect
    if (isPerfect(n)) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }

    return 0;
}
